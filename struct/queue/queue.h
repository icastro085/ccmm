#include <stdio.h>
#include <stdlib.h>

#ifndef _QUEUE_STRUCTURE_
#define _QUEUE_STRUCTURE_

typedef struct noh_queue {
  void* value;
  noh_queue* previous;
} noh_queue;

class Queue {
  private:
    int size;
    noh_queue* first;
    noh_queue* last;

  public:
    Queue();
    void push(void* value);
    void* pop();
    bool is_empty();
    int length();
};

Queue::Queue() {
  this->first = NULL;
  this->last = NULL;
  this->size = 0;
}

void Queue::push(void* value) {
  noh_queue* noh = (noh_queue*) malloc(sizeof(noh_queue));

  noh->value = value;
  noh->previous = NULL;

  if (this->last == NULL) {
    this->first = this->last = noh;
  } else {
    this->last->previous = noh;
    this->last = noh;
  }

  this->size++;
}

void* Queue::pop() {
  if (this->is_empty()) {
    return NULL;
  }

  void* value = this->first->value;
  noh_queue* new_first = this->first->previous;

  free(this->first);

  this->first = new_first;
  this->size--;

  if (this->first == NULL) {
    this->last = NULL;
  }

  return value;
}

bool Queue::is_empty() {
  return this->first == NULL ? true : false;
}

int Queue::length() {
  return this->size;
}

#endif
