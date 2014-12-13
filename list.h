#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdlib.h>

typedef struct listNode {
  struct listNode *previous;
  struct listNode *next;
} ListNode;

typedef struct list {
  struct listNode head;
} List;

/*
 * Initialises a List struct for use.
 */
void list_init(List *list);

/*
 * Adds the new node to the list between the given nodes.
 */
void list_add_between(ListNode *newNode, ListNode *prev, ListNode *next);

/*
 * Removes the given node from the list.
 */
void list_remove(ListNode *node);

/*
 * Adds the new node to the front of the list
 */
void list_push_front(List *list, ListNode *newNode);

/*
 * Removes and returns the node at the front of the list.
 */
ListNode *list_pop_front(List *list);

/*
 * Adds the new node to the back of the list.
 */
void list_push_back(List *list, ListNode *newNode);

/*
 * Removes and returns the node at the back of the list.
 */
ListNode *list_pop_back(List *list);

// TODO: Maybe implement a few more list functions?

#endif // LIST_H
