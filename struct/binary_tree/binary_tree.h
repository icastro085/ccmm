#include <stdio.h>
#include <stdlib.h>

#ifndef _BINARY_TREE_STRUCTURE_
#define _BINARY_TREE_STRUCTURE_

typedef struct noh_binary_tree {
  int value;
  noh_binary_tree *left, *right;
} noh_binary_tree;

class BinaryTree {
  private:
    noh_binary_tree* root;
    noh_binary_tree* create_noh(int value);
    noh_binary_tree* insert_in_tree(noh_binary_tree* root, int value);

  public:
    BinaryTree();
    void push(int value);
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

noh_binary_tree* BinaryTree::insert_in_tree(noh_binary_tree* noh, int value) {
  if (noh == NULL) {
    return create_noh(value);
  }

  if (value < noh->value) {
    noh->left = this->insert_in_tree(noh->left, value);
  } else {
    noh->right = this->insert_in_tree(noh->right, value);
  }

  return noh;
}

void BinaryTree::push(int value) {
  noh_binary_tree* noh = this->create_noh(value);
  noh->value = value;

  if (this->root == NULL) {
    this->root = this->insert_in_tree(NULL, value);
  } else {
    this->insert_in_tree(this->root, value);
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
