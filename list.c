#include "list.h"

void list_init(List *list) {
  list->head.previous = &(list->head);
  list->head.next = &(list->head);
}

void list_add_between(ListNode *newNode, ListNode *prev, ListNode *next) {
  prev->next = newNode;

  newNode->previous = prev;
  newNode->next = next;

  next->previous = newNode;
}

void list_remove(ListNode *node) {
  node->previous->next = node->next;
  node->next->previous = node->previous;

  node->previous = NULL;
  node->next = NULL;
}

void list_push_front(List *list, ListNode *newNode) {
  list_add_between(newNode, &(list->head), list->head.next);
}

ListNode *list_pop_front(List *list) {
  ListNode *node = list->head.next;
  list_remove(node);
  return node;
}

void list_push_back(List *list, ListNode *newNode) {
  list_add_between(newNode, list->head.previous, &(list->head));
}

ListNode *list_pop_back(List *list) {
  ListNode *node = list->head.previous;
  list_remove(node);
  return node;
}
