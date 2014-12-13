#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// Test the implementation with a simple list of ints.

typedef struct intListNode {
  int i;
  ListNode node;
} IntListNode;

void print_int_list(List *list) {
  for (ListNode *node = list->head.next; node != &(list->head); node = node->next) {
    IntListNode *intNode = (IntListNode*) container_of(node, IntListNode, node);
    printf("%i ", intNode->i);
  }
  putchar('\n');
}

int main() {
  // Make a few nodes and the list.
  List list;
  list_init(&list);
  IntListNode test1 = {1, {NULL, NULL}};
  IntListNode test2 = {2, {NULL, NULL}};
  IntListNode test3 = {3, {NULL, NULL}};

  // Add them to the list in order.
  list_push_back(&list, &(test1.node));
  list_push_back(&list, &(test2.node));
  list_push_back(&list, &(test3.node));

  puts("push_back in order, should be: 1 2 3");
  print_int_list(&list);

  puts("pop_back and push_front, should be: 3 1 2");
  list_push_front(&list, list_pop_back(&list));
  print_int_list(&list);

  puts("pop_front then push_back twice, should be: 2 3 1");
  list_push_back(&list, list_pop_front(&list));
  list_push_back(&list, list_pop_front(&list));
  print_int_list(&list);

  puts("pop_front everything then push_front 1, should be: 1");
  for (int i=0; i<3; i++) { list_pop_front(&list); }
  list_push_front(&list, &(test1.node));
  print_int_list(&list);

  puts("pop_back, should be empty.");
  list_pop_back(&list);
  print_int_list(&list);

  return 0;
}
