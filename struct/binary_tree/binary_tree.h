#include <stdio.h>
#include <stdlib.h>

#ifndef _BINARY_TREE_STRUCTURE_
#define _BINARY_TREE_STRUCTURE_

typedef struct noh_binary_tree {
  int value;
  noh_binary_tree *left, *right;
} noh_binary_tree;

typedef bool (*compare)(void* value, noh_binary_tree* noh);

bool compare_for_left(void* value, noh_binary_tree* noh) {
  int* value_int = (int*) value;
  if (*value_int < noh->value) {
    return true;
  }

  return false;
}

class BinaryTree {
  private:
    noh_binary_tree* root;
    noh_binary_tree* create_noh(int value);
    noh_binary_tree* insert_in_tree(noh_binary_tree* root, int value, compare c);

  public:
    BinaryTree();
    void push(int value);
    void push(int value, compare c);
    bool is_empty();
    void inorder(noh_binary_tree* root);
    void print_tree();
};

BinaryTree::BinaryTree() {
  this->root = NULL;
}

noh_binary_tree* BinaryTree::create_noh(int value) {
  noh_binary_tree* noh = (noh_binary_tree*) malloc(sizeof(noh_binary_tree));
  noh->value = value;
  noh->left = noh->right = NULL;
  return noh;
}

noh_binary_tree* BinaryTree::insert_in_tree(
  noh_binary_tree* noh,
  int value,
  compare c
) {
  if (noh == NULL) {
    return create_noh(value);
  }

  if (c(&value, noh)) {
    noh->left = this->insert_in_tree(noh->left, value, c);
  } else {
    noh->right = this->insert_in_tree(noh->right, value, c);
  }

  return noh;
}

void BinaryTree::push(int value) {
  this->push(value, &compare_for_left);
}

void BinaryTree::push(int value, compare c) {
  noh_binary_tree* noh = this->create_noh(value);
  noh->value = value;

  if (this->root == NULL) {
    this->root = this->insert_in_tree(NULL, value, c);
  } else {
    this->insert_in_tree(this->root, value, c);
  }
}

void BinaryTree::inorder(noh_binary_tree* root) {
  if (root != NULL) { 
    this->inorder(root->left);
    printf("%d \n", root->value);
    this->inorder(root->right);

    free(root);
  } 
}

void BinaryTree::print_tree() {
  this->inorder(this->root);
}

#endif
