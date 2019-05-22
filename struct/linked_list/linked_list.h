#include <stdio.h>
#include <stdlib.h>

#ifndef _LINKED_LIST_STRUCTURE_
#define _LINKED_LIST_STRUCTURE_

typedef struct noh_linked_list {
  void* value;
  noh_linked_list* next;
} noh_linked_list;

class LinkedList {
  private:
    int size;
    noh_linked_list* head;

    noh_linked_list* find_by_index(int index);

  public:
    LinkedList();
    void push(void* value,  int index);
    void push(void* value);
    void* pop();
    void* pop(int index);
    void* seek(int index);
    bool is_empty();
    int length();
};

LinkedList::LinkedList() {
  this->head = NULL;
  this->size = 0;
}

noh_linked_list* LinkedList::find_by_index(int index) {
  noh_linked_list* noh = this->head;

  for (int i = 1; i <= index; i++) {
    noh = noh->next;
  }

  return noh;
}

void LinkedList::push(void* value, int index) {
  if (index > this->length()) {
    
  }

  noh_linked_list* noh = (noh_linked_list*) malloc(sizeof(noh_linked_list));
  noh->value = value;

  if (index == 0) {
    noh->next = this->head;
    this->head = noh;
  } else {
    noh_linked_list* noh_found = this->find_by_index(index - 1);
    noh->next = noh_found->next;
    noh_found->next = noh;
  }

  this->size++;
}

void LinkedList::push(void* value) {
  this->push(value, this->size);
}

void* LinkedList::pop(int index) {
  if (this->is_empty() || index > this->length()) {
    return NULL;
  }

  noh_linked_list* noh_found = this->find_by_index(index);
  void* value = noh_found->value;

  if (index == 0) {
    this->head = noh_found->next;
  }

  free(noh_found);

  this->size--;

  return value;
}

void* LinkedList::pop() {
  return this->pop(0);
}

bool LinkedList::is_empty() {
  return this->head == NULL ? true : false;
}

int LinkedList::length() {
  return this->size;
}

void* LinkedList::seek(int index) {
  noh_linked_list* noh_found = this->find_by_index(index);
  return noh_found->value;
}

#endif
