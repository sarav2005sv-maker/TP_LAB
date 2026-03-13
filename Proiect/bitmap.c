#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  if (argc != 3)
    {
      fprintf(stderr,"trebuie 3 argumente\n");
      exit(-1);
    }
  FILE* f = fopen(argv[1],"r");
  if (f == NULL)
    {
      fprintf(stderr,"err deschidere fisier\n");
      exit(-1);
    }

  FILE* out = fopen(argv[2],"w");
  if (out == NULL)
    {
      fprintf(stderr,"err deschidere fisier\n");
      exit(-1);
    }
  uint8_t array[54];
  fread(array,1,54,f);
  //scriem header si header info din f_in si in f_out
  fwrite(array,1,54,out);
  fseek(f,0,SEEK_SET);
  uint16_t type;
  uint32_t off; //offset pixel array
  uint32_t compression;
  fread(&type,2,1,f);
  if (type != 0x4d42) //verificam ca fisierul sa fie de tip bmp
    {
      fprintf(stderr,"fisierul nu este de tip BMP\n");
      fclose(f);
      fclose(out);
      exit(-1);
    }
  printf("type: %x\n",type);

  //obtinem dimensiunea fisierului
  uint32_t size;
  fseek(f,2,SEEK_SET);
  fread(&size,4,1,f);
  printf("size: %x\n",size);
  
  //obtinem offset-ul array-ul de pixeli
  fseek(f,10,SEEK_SET);
  fread(&off,1,1,f);
  printf("offset pixel array: %x\n",off);

  //obtinem compresia fisierului
  fseek(f,30,SEEK_SET);
  fread(&compression,1,1,f);
  printf("compression: %x\n",compression);
  if (compression != 0)
    {
      fprintf(stderr,"file is compressed\n");
      fclose(f);
      fclose(out);
      exit(-1);
    }

  //obtinem nr de biti/pixel
  uint16_t bpp;
  fseek(f,28,SEEK_SET);
  fread(&bpp,2,1,f);
  if (bpp != 0x18)
    {
      fprintf(stderr,"fisierul nu are 24 biti/pixel\n");
      fclose(f);
      fclose(out);
      exit(-1);
    }
  printf("bpp: %x\n",bpp); //hexa

  //obtinem lungimea unei linii in pixeli
  uint32_t length;
  fseek(f,18,SEEK_SET);
  fread(&length,4,1,f);
  printf("length: %x\n",length);
  
  //Header - 14B
  //Info_Header - 40B
  //bytes in pixel array
  uint32_t nr_bytes = size - 54;
  printf("%d\n",nr_bytes);
  
  //mutam cursorul la inceputul pixel array
  fseek(f,off,SEEK_SET);
  fseek(out,off,SEEK_SET);
  for(int i = 0; i < nr_bytes;)
    {
      uint8_t aux[3];
      fread(aux,1,3,f);
      uint8_t gri = 0.299 * aux[2] + 0.587 * aux[1] + 0.114 * aux[0];     
      uint8_t grey[3];
      grey[0] = gri;
      grey[1] = gri;
      grey[2] = gri;        
      fwrite(grey,1,3,out);
      i = i + 3;

      //se aliniaza la 4 bytes - e posibil sa fie nevoie de padding
      int p = (4 - ((length * bpp) % 4)) % 4;
      uint8_t padding[p];
      fread(padding,1,p,f);
      fwrite(padding,1,p,out);
      i = i + p;
    }
  
  if (fclose(f) != 0)
    {
      fprintf(stderr,"err inchidere fisier\n");
      exit(-1);
    }
  if (fclose(out) != 0)
    {
      fprintf(stderr,"err inchidere fisier\n");
      exit(-1);
    }
  return 0;
}
