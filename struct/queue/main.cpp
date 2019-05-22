#include <stdio.h>
#include "queue.h"

Queue queue;

void print_states() {
  printf("Is Empty? %s \n", queue.is_empty() ? "Yes" : "No");
  printf("Total: %d\n\n", queue.length());
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
    queue.push(number);
    printf("insert number: %d \n", *number);
  }

  print_states();
  // -----------------------------------------------------

  while(!queue.is_empty()) {
    number = (int*) queue.pop();
    printf("get number: %d \n", *number);
  }

  print_states();

  return 0;
}
