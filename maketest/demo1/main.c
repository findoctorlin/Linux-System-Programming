#include<stdio.h>
#include"header.h"

int main()
{
  printf("I am in main.c\n");
  printf("Calling hello function\n");
  hello();
  printf("Calling add function\n");
  add(3,6);
  printf("Calling mul function\n");
  mul(3,6);
  printf("Back to main.c\n");
}
