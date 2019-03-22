//List.c

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

LINK makeEmpty () /* creates an empty list */
{
    LINK head = (LINK) malloc( sizeof (struct Node) );
    head->next = NULL;
    head->elem = 0;
    head->data[0]='\0';
    return head;
}

int isEmpty(LINK head) /* returns true if the list is empty */
{
    return ( head->next == NULL );
}

int deleteFirst(LINK head) /* removes the first element from the list and returns true if the operation is done successfully */
{
    LINK temp;
    if ( isEmpty(head) )
        return FALSE;
    temp = head->next;

    head->next = temp->next;
    free (temp);
    return TRUE;
}

int insertAsFirst(LINK head, LINK node) /* inserts an element as the first of the list and returns true if the operation is done successfully */
{

    node->next = head->next;
    head->next = node;
    return TRUE;
}

void clearList(LINK head) /* makes the list empty */
{

    while ( !isEmpty(head) )
        deleteFirst (head);
}

void update(LINK head, char word[]) /* searches the word in the list and update it */
{
    LINK curr;

    /* create the first item */
    if ( isEmpty(head) ){
        LINK temp=(LINK) malloc (sizeof (struct Node));
        /* set the counter */
        temp->elem = 1;
        strcpy(temp->data,word);
        insertAsFirst(head, temp);
        return;
    }

    /* the first item has the word as data */
    curr = head->next;
    if(curr != NULL && (!strcmp(curr->data, word))){
        /* increase the counter */
        curr->elem+=1;
        return;
    }

    //search the word and move the node to front of the list */
    while ( curr->next != NULL ) {
        if(!strcmp(curr->next->data, word)){
            LINK temp;
            /* increase the counter */
            curr->next->elem+=1;

            temp = curr->next;

            curr->next = curr->next->next;
            insertAsFirst(head, temp);
            return;
        }
        curr = curr->next;
    }

    { /* we did not find the word and created the new node */
        LINK temp=(LINK) malloc (sizeof (struct Node));
        /* set the counter */
        temp->elem = 1;
        strcpy(temp->data,word);
        insertAsFirst(head, temp);
    }


}

void showList(LINK head) /* displays all elements in the list */
{
    LINK curr = head->next;
    while ( curr != NULL ) {
        printf ("%s: %d\n", curr->data, curr->elem);
        curr = curr->next;
    }
}

void list2file(LINK head, FILE* f) /* write all elements from the list to the file*/
{
    LINK curr = head->next;
    while ( curr != NULL ) {
        fprintf (f, "%s: %d\n", curr->data, curr->elem);
        curr = curr->next;
    }
}
