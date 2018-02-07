
#include "stdio.h"
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node, *node;

node new_node(int data) {
  node newNode = (node) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void push(node &headRef, int data) {
  node newNode = new_node(data);
  newNode->next = headRef;
  if (headRef) {
    headRef->prev = newNode;
  }
  headRef = newNode;
}

void insert_after(node &prevRef, int data) {
  
}
