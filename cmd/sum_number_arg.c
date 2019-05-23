#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argsv) {
  int n1, n2;

  n1 = atoi(argsv[1]);
  n2 = atoi(argsv[2]);

  printf("Sum is %d \n", n1 + n2);
  return 0;
}
