#include <stdio.h>
#define MAX_SIZE 1000

typedef struct{
  int array[MAX_SIZE];
  int current_size;
}stack_t;

void push(int elem,stack_t* stack)
{
  if (stack->current_size == MAX_SIZE)
    {
      printf("stiva este plina\n");
      return;
    }
  stack->array[stack->current_size++] = elem; 
}

int pop(stack_t* stack)
{
  if (stack->current_size == 0)
    {
      printf("stiva este goala\n");
      return -1;
    }
  return stack->array[--stack->current_size];
}

int peek(stack_t* stack)
{
  if (stack->current_size == 0)
    {
      printf("stiva este goala\n");
      return -1;
    }
  printf("%d\n",stack->array[stack->current_size - 1]);
  return stack->array[stack->current_size - 1];
}

void display(stack_t* stack)
{
  if (stack->current_size == 0)
    {
      printf("stiva este goala\n");
      return;
    }
  printf("elementele din stiva sunt: ");
  for (int i = stack->current_size-1; i >= 0; i--)
    {
      printf("%d ",stack->array[i]);
    }
  printf("\n");
}

int main(void)
{
  stack_t stiva;
  stiva.current_size = 0;
  push(10,&stiva);
  push(20,&stiva);
  push(30,&stiva);
  pop(&stiva);
  display(&stiva);
  printf("%d\n",stiva.current_size);
  peek(&stiva);
  printf("%d\n",stiva.current_size);
  return 0;
}
