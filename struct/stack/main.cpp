#include <stdio.h>
#include "stack.h"

Stack stack;

void print_states() {
  printf("Is Empty? %s \n", stack.is_empty() ? "Yes" : "No");
  printf("Total: %d\n\n", stack.length());
}

int* alloc_number() {
  return (int*) malloc(sizeof(int));
}

int main(int argc, char** argsv) {
  int* number;
  int i;

  print_states();
  // -----------------------------------------------------

  for (i = 1; i < argc; i++) {
    number = alloc_number();
    *number = atoi(argsv[i]);
    stack.push(number);
    printf("insert number: %d \n", *number);
  }

  print_states();
  // -----------------------------------------------------

  while(!stack.is_empty()) {
    number = (int*) stack.pop();
    printf("get number: %d \n", *number);
  }

  print_states();

  return 0;
}
