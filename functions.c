#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

void print_list(struct node * someNode){
  if (someNode == NULL) {printf("[ ]\n");}
  else {
    printf("[");
    while (someNode != NULL) {
      printf(" %d", someNode->i);
      someNode = someNode->next;
    }
    printf(" ]\n");
  }
}

struct node * insert_front(struct node * someNode, int n) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->i = n;
  newNode->next = someNode;
  return newNode;
}

struct node * remove_node(struct node * front, int data) {
  if (front == NULL) {return front;}

  struct node *previous = front;
  struct node *current = front->next;
  if(front->i == data) {
    free(front);
    front = NULL;
    return current;
  }

  while(current != NULL){
    if(current->i == data) {
      previous->next = current->next;
      free(current);
      current = NULL;
      return front;
    }
    previous = current;
    current = current->next;
  }
  return front;
}

struct node * free_list(struct node * someNode){
  struct node *current = someNode;
  while(someNode != NULL){
    printf("freeing node: %d\n", someNode->i);
    current = someNode->next;
    free(someNode);
    someNode = current;
    print_list(someNode);
  }
  return someNode;
}
