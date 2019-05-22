#include <stdio.h>
#include "linked_list.h"

LinkedList list;

void print_states() {
  printf("Is Empty? %s \n", list.is_empty() ? "Yes" : "No");
  printf("Total: %d\n\n", list.length());
}

int* alloc_number() {
  return (int*) malloc(sizeof(int));
}

int main(int argc, char** argsv) {
  int* number;

  print_states();

  number = alloc_number();
  *number = 1;

  list.push(number);
  printf("insert number %d\n", *number);

  number = alloc_number();
  *number = 3;
  list.push(number);

  printf("insert number %d\n", *number);

  number = alloc_number();
  *number = 2;
  list.push(number, 1);

  printf("insert number %d at position 1\n", *number);

  print_states();

  number = (int*) list.pop(2);
  printf("number %d\n", *number);

  number = (int*) list.seek(1);
  printf("number by seek %d\n", *number);

  number = (int*) list.pop(1);
  printf("number by pop %d\n", *number);

  number = (int*) list.pop(0);
  printf("number %d\n", *number);

  print_states();

  return 0;
}
