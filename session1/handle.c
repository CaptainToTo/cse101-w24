#include "list.h"

#include <stdio.h>

// reverse the list in-place
void reverse_list(LinkedList *list) {
    // YOUR CODE HERE
}

// determine if the list contains a cycle
bool contains_cycle(LinkedList *list) {
    // YOUR CODE HERE
}

int main(void) {

    // reverse list ===================================

    LinkedList *list = create_list();
    prepend(list, 1);
    prepend(list, 2);
    prepend(list, 3);
    prepend(list, 4);
    prepend(list, 5);

    printf("original list: ");
    print_list(list);

    reverse_list(list);

    printf("reversed list: ");
    print_list(list);

    free_list(&list);

    // has cycle ======================================

    LinkedList *list_no_cycle = create_list();
    prepend(list_no_cycle, 1);
    prepend(list_no_cycle, 2);
    prepend(list_no_cycle, 3);

    prepend(list_no_cycle, 1);
    prepend(list_no_cycle, 2);
    prepend(list_no_cycle, 3);

    prepend(list_no_cycle, 4);
    prepend(list_no_cycle, 5);

    if (!contains_cycle(list_no_cycle)) {
        printf("first list does not contain a cycle\n");
    } else {
        printf("first list does not contain cycle, but contains_cycle() returned true\n");
    }

    free_list(&list_no_cycle);

    LinkedList *list_with_cycle = create_list();
    prepend(list_with_cycle, 1);
    prepend(list_with_cycle, 2);
    prepend(list_with_cycle, 3);
    prepend(list_with_cycle, 4);
    prepend(list_with_cycle, 5);

    connect(list_with_cycle, 2); // connects 5 -> 4 -> 3 -> 2 -> 1
                                 //                    ^---------|
    if (contains_cycle(list_with_cycle)) {
        printf("second list does contain a cycle\n");
    } else {
        printf("second list does contain cycle, but contains_cycle() returned false\n");
    }

    //free_list(&list_with_cycle); // this doesn't work
}
