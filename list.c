#include "list.h"
#include <string.h>


#define FIRST 1
#define SECOND 2
#define NONE -1

//Identifies identifiers in the given file
// Search if the identifier exists in the list
// Otherwise insert into the list
void identifiers(List *list, ID *id) {

    Node *associate = createNewNode(id);
    int index = listSearch(list, associate);

    if (index < 0) {
        insertNewNode(list, associate);
    } else {
        insertAtFirst(list, index);
    }
}

//Creates list and head of linked list
List *createList() {
    List *MyList = malloc(sizeof(List));
    MyList->top = NULL;
    MyList->size = 0;

    return MyList;

}

//New node based of the type of identifier
Node *createnode(ID *id) {

    // Allocate space for the new node
    Node *newnode = malloc(sizeof(Node));
    newnode->identifier = malloc(sizeof(ID));
    strcpy(newnode->identifier, *id);
    newnode->count = 1;
    newnode->next = NULL;
    return newnode;
}

//Inserts new node into list
int insert(List *list, Node *node) {

    // Check that the top of the list is not empty
    if (list->top == NULL) {

        list->top = node;
        list->size++;
        return 0;

        //Checks for second node to be empty
    } else if (list->top->next == NULL) {
        list->top->next = node;
        list->size++;
        return 0;
        //Top Node
    } else {
        Node *traverse = list->top;

        while (traverse->next != NULL) {

            traverse = traverse->next;

            //Ptr to the given node
            if (traverse->next == NULL) {
                traverse->next = node;
                list->size++;
                return 0;
            }
        }
    }

    return -1;

}

//Searches for node in the list
int search(const List *list, Node *node) {
    int count = 1;
    if (list->top == NULL) {
        return NONE;
    }

    // Point to the top of the list
    // If the element is at the beginning return right away
    Node *top = list->top;
    if (strcmp(top->identifier, node->identifier) == 0) {
        top->count++;
        return FIRST;

    } else if (top->next != NULL) {
        if (strcmp(top->next->identifier, node->identifier) == 0) {
            top->next->count++;
            return SECOND;
        }

    }
    if (top->next == NULL) {
        return NONE;
    } else {
        // Not found in the first or second, loop through
        while (top->next != NULL) {

            if (strcmp(top->next->identifier, node->identifier) == 0) {
                count++;
                top->next->count++;
                return count;
            }

            top = top->next;
            count++;
        }
    }
    return NONE;


}

//Moves node to the front of the linked list
int movetofront(List *list, int index) {
    int count = 1;
    Node *current = list->top;
    Node *first = list->top;
    Node *second = list->top->next;

    //Id last node
    if (index == list->size) {

        while (count < list->size) {
            count++;
            if (count == list->size) {
                current->next->next = list->top;
                list->top = current->next;
                current->next = NULL;
                return 0;
            }
            current = current->next;
        }

    } else if (index == 2 && list->top->next->next == NULL) {

        current->next->next = list->top;
        list->top = current->next;
        return 0;

    } else if (index == 2 && list->top->next->next != NULL) {

        current->next = list->top->next->next;
        second->next = current;
        list->top = second;
        return 0;

    } else {

        Node *dummy = malloc(sizeof(Node));

        while (count < index) {
            count++;
            if (count == index) {
                dummy->identifier = malloc(sizeof(ID));
                strcpy(dummy->identifier, current->next->identifier);
                dummy->count = current->next->count;
                current->next = current->next->next;
                dummy->next = list->top;
                list->top = dummy;
                return 0;
            }
            current = current->next;
        }
    }
    return -1;
}