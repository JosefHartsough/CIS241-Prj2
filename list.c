#include "list.h"


/* creates an empty list */
LINK makeEmpty(){
    LINK head = (LINK) malloc( sizeof (struct Node) );
    head->next = NULL;
    head->elem = 0;
    return head;
}


/* returns true if the list is empty */
int isEmpty(LINK head){
    return ( head->next == NULL );
}

/* returns true if the list is full */
int isFull(LINK head){
    return FALSE;
}

/* removes the first element from the list and
   returns true if the operation is done successfully */
int deleteFirst(LINK head, int *p){
    LINK temp;
    if ( isEmpty(head) )
        return FALSE;
    temp = head->next;
    *p = temp->elem;
    head->next = temp->next;
    free (temp);
    return TRUE;
}

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
void clearList(LINK head){
    int temp;
    while (!isEmpty(head))
        deleteFirst(head);
}

/* displays all elements in the list */
void showList(LINK head){
    LINK curr = head->next;
    while ( curr != NULL ) {
        printf ("  %d", curr->elem);
        curr = curr->next;
    }
}