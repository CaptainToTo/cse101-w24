#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    int length;
} LinkedList;

/**
 * allocates a new linked list node on the heap.
 * @param data the value to store in the new node.
*/
Node *create_node(int data);

/**
 * frees the given linked list node.
 * @param nodePtr the ptr to caller's node ptr.
*/
void free_node(Node **nodePtr);

/**
 * allocates a new linked list on the heap. new lists are empty.
*/
LinkedList *create_list(void);

/**
 * frees the given linked list, and all nodes it contains.
 * @param listPtr the ptr to the callers LinkedList ptr.
*/
void free_list(LinkedList **listPtr);

/**
 * prepends a new node to the linked list.
 * @param list the linked list that will be prepended to.
 * @param data the value the new node will store.
*/
void prepend(LinkedList *list, int data);

/**
 * sets the tail node's next ptr to the ind-th node.
 * once a cycle is made, all list iterations will result in infinite loops.
 * @param list the linked list that will be searched through.
 * @param ind the index of node to connect to.
*/
void connect(LinkedList *list, int ind);

/**
 * prints a list's nodes to stdout.
 * @param list the list that will be printed.
*/
void print_list(LinkedList *list);

#endif