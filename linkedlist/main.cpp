
#include "stdio.h"
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} *node, Node;

node new_node(const node n) {
  // assert(n);
  node newNode = (node) malloc(sizeof(Node));
  newNode->data = n->data;
  newNode->next = NULL;
  return newNode;
}

void push(node *headRef, int data) {
  node newNode = (node) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = *headRef;
  *headRef = newNode;
}

void pushr(node &headRef, int data) {
  node newNode = (node) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = headRef;
  headRef = newNode;
}

node find_tail(const node head) {
  node cur = head;
  while(cur && cur->next) {
    cur = cur->next;
  }
  return cur;
}


node copy_list(const node head) {
  node cur = head;
  node newHead = NULL;
  node *newLastLoc = &newHead;
  while (cur) {
    pushr(*newLastLoc, cur->data);
    newLastLoc = &((*newLastLoc)->next);
    cur = cur->next;
  }
  return newHead;
}

node copy_list1(const node head) {
  node cur = head;
  Node dummy; dummy.next = NULL;
  node newTail = &dummy;
  while (cur) {
    pushr(newTail->next, cur->data);
    newTail = newTail->next;
    cur = cur->next;
  }
  return dummy.next;
}

node copy_list_recursive(const node head) {
  node nd = NULL;
  if (head) {
    nd = new_node(head);
    nd->next = copy_list_recursive(head->next);
  }
  return nd;
}

void append(node &headRef, int data) {
  node newNode = (node) malloc(sizeof(Node));
  pushr(find_tail(headRef)->next, data);
}

node buildList(const int length) {
  Node dummy;
  node tail = &dummy;
  dummy.next = NULL;
  for (int i = 0; i < length; i++) {
    pushr(tail->next, i);
    tail = tail->next;
  }
  return dummy.next;
}

node buildListReverse(const int length) {
  node head = NULL;
  for(int i = 0; i < length; i++) {
    pushr(head, i);
  }
  return head;
}

int Length(const node head) {
  node cur = head;
  int l = 0;
  while(cur) {
    l++;
    cur = cur->next;
  }
  return l;
}

void freeList(node head) {
  node cur = head;
  while (cur) {
    node tmp = cur;
    cur = cur->next;
    delete(tmp);
  }
}

void print(const char *label, const node head) {
  node tmp = head;
  printf("Linked list \"%s\" with length: %i.\n", label, Length(head));
  while(tmp) {
    printf("%i\t", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

int main() {
  node head = buildListReverse(5);
  print("head", head);
  node head1 = buildList(7);
  print("head1", head1);

  printf("insert 10 and 23 to list.\n");
  append(head1, 10);
  append(head1, 23);
  print("head1_after_append", head1);

  node nh1 = copy_list1(head1);
  print("copied_list1", nh1);
  
  node nh = copy_list(head1);
  print("copied_list", nh);

  node nh2 = copy_list_recursive(head1);
  print("copied_list_recursive", nh2);
  freeList(head);
  freeList(head1);
  freeList(nh);
  freeList(nh1);
  freeList(nh2);
  return 0;
}
