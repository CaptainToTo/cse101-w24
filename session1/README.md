# Session 1 - Linked Lists

You are given an implemented LinkedList ADT in list.h and list.c.\
Your goal is the finish the functions in handle.c.

## Reverse a Linked List
The reverse() function requires you to invert the order of a given linked list **in-place**. This means you are not allowed to allocate new memory, so you cannot create a new list.

## Detect a Cycle
The contains_cycle() function will return true if a given linked list loops back into itself. The cycle will always start at the tail, but can connect back to any other node in the list.

Once you've made contains_cycle(), you'll notice that free_list() doesn't work on a list with a cycle. How can you change free_list() to work properly, using your solution for contains_cycle()?

## Create a Sorted List
The sort() function will return a new linked list containing the elements of a given array of integers in sorted order. 
