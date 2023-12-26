#include "list.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

Node *create_node(int data) {
    Node *n = (Node *) calloc(1, sizeof(Node));
    n->data = data;
    return n;
}

void free_node(Node **nodePtr) {
    if (nodePtr == NULL || *nodePtr == NULL) return;
    free(*nodePtr);
    *nodePtr = NULL;
}

LinkedList *create_list() {
    LinkedList *l = (LinkedList *) calloc(1, sizeof(LinkedList));
    return l;
}

void free_list(LinkedList **listPtr) {
    if (listPtr == NULL || *listPtr == NULL) return;

    Node *cur = (*listPtr)->head;
    Node *prev = NULL;
    while (cur != NULL) {
        prev = cur;
        cur = cur->next;
        free_node(&prev);
    }

    free(*listPtr);
    *listPtr = NULL;
}

void prepend(LinkedList *list, int data) {
    if (list == NULL) return;
    Node *n = create_node(data);
    n->next = list->head;
    list->head = n;
    list->length++;
}

void connect(LinkedList *list, int ind) {
    if (list == NULL) return;
    if (ind < 0 || ind >= list->length) return;

    // iterate to index of starting node
    Node *cur = list->head;
    for (int i = 0; i < ind; i++) {
        cur = cur->next;
    }

    // cache the starting node
    Node *cycle_start = cur;

    // continue to tail
    while (cur->next != NULL) {
        cur = cur->next;
    }

    // set tail's next to the starting node
    cur->next = cycle_start;
}

void print_list(LinkedList *list) {
    if (list == NULL) return;
    Node *cur = list->head;
    while (cur != NULL) {
        printf("%d, ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
