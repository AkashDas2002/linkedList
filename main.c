#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main() {
  struct node * anode = NULL;
  printf("Printing empty list:\n");
  print_list(anode);
  printf("Adding 0 through 9 to the linked list:\n");
  int i = 0;
  for(int i = 0; i < 10; i++){
    anode = insert_front(anode, i);
    print_list(anode);
  }

  printf("Removing 4\n");
  anode = remove_node(anode, 4);
  print_list(anode);

  printf("Removing 9\n");
  anode = remove_node(anode, 9);
  print_list(anode);

  printf("Removing 0\n");
  anode = remove_node(anode, 0);
  print_list(anode);

  printf("Removing 1\n");
  anode = remove_node(anode, 1);
  print_list(anode);

  printf("Removing 10\n");
  anode = remove_node(anode, 10);
  print_list(anode);

  free_list(anode);

  printf("Our new linked list is:\n");
  print_list(anode);
  return 0;
}
