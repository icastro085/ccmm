#include <stdio.h>
#include <stdlib.h>

int main(int argc, int** argv) {
  int n1, n2;

  printf("Enter number 1: ");
  scanf("%d", &n1);

  printf("Enter number 2: ");
  scanf("%d", &n2);

  printf("Sum is %d \n", n1 + n2);

  return 0;
}
