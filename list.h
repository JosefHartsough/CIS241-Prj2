#include <stdio.h>
#include <stdlib.h>
//True is 1
#define TRUE 1

//False is -1
#define FALSE 0

typedef struct Node* LINK;
struct Node {
    char* elem;
    int count;
    LINK next;
};

/* creates an empty list */
LINK makeEmpty();

/* returns true if the list is empty */
int isEmpty(LINK head);

/* returns true if the list is full */
int isFull(LINK head);

/* removes the first element from the list and
   returns true if the operation is done successfully */
int deleteFirst(LINK head);

/* inserts an element as the first of the list and
   returns true if the operation is done successfully */
int insertAsFirst(char* d, LINK head);

/* inserts an element as the first of the list with a specific value and
   returns true if the operation is done successfully */
int insertAsFirstVal(char* d, int count, LINK head);

/* Removes the first value from seach */
int removeVal(char* value, LINK head);

/* Search for specific item and moves it to the front of the list */
int search(char* value, LINK head);

/* Adds value to list */
int addVal(char* value, int add, LINK head);

/* makes the list empty */
void clearList(LINK head);

/* displays all elements in the list */
void showList(LINK head);