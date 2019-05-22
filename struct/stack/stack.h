#include <stdio.h>
#include <stdlib.h>

#ifndef _STACK_STRUCTURE_
#define _STACK_STRUCTURE_

typedef struct noh_stack {
  void* value;
  noh_stack* next;
} noh_stack;

class Stack {
  private:
    int size;
    noh_stack* top;

  public:
    Stack();
    void push(void* node);
    void* pop();
    bool is_empty();
    int length();
};

Stack::Stack() {
  this->top = NULL;
  this->size = 0;
}

void Stack::push(void* value) {
  noh_stack* noh = (noh_stack*) malloc(sizeof(noh_stack));

  noh->value = value;
  noh->next = this->top;

  this->top = noh;
  this->size++;
}

void* Stack::pop() {
  if (this->is_empty()) {
    return 0;
  }

  void* value = this->top->value;
  noh_stack* new_top = this->top->next;

  free(this->top);

  this->top = new_top;
  this->size--;

  return value;
}

bool Stack::is_empty() {
  return this->top == NULL ? true : false;
}

int Stack::length() {
  return this->size;
}

#endif
