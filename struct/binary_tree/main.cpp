#include <stdio.h>
#include "binary_tree.h"

BinaryTree tree;

int* alloc_number() {
  return (int*) malloc(sizeof(int));
}

int main(int argc, char** argsv) {

  tree.push(2);
  tree.push(3);
  tree.push(1);
  tree.push(5);
  tree.push(4);

  tree.print_tree();

  return 0;
}
