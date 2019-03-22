//list.h

#ifndef list_h
#define list_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50  //maximum characters in the word

typedef struct Node* LINK;

struct Node {
    int elem;
    char data[MAX];
    LINK next;
};

LINK makeEmpty (void); /* creates an empty list */
int isEmpty(LINK head); /* returns true if the list is empty */
void clearList(LINK head); /* makes the list empty */
int deleteFirst(LINK head); /* removes the first element from the list and returns true if the operation is done successfully */
int insertAsFirst( LINK head, LINK node); /* inserts an element as the first of the list and returns true if the operation is done successfully */
void showList(LINK head); /* displays all elements in the list */
void update(LINK head, char word[]); /* searches the word in the list and update it */
void list2file(LINK head, FILE* f); /* write all elements from the list to the file*/

#endif
