#include <stdlib.h>
#include <stdio.h>
#ifndef H_LIST
#define H_LIST


typedef char * ID;
typedef int count;

//Struct for node with identifiers, count of how many and node to next node.
struct Nodes{
    ID identifier;
    int count;
    struct Nodes * next;
};

typedef struct Nodes Node;


// Linked list with nodes and pointers to next node
struct Lists {
    Node *top;
    int size;
};

typedef struct Lists List;

//Creates new node
Node * createNewNode(ID * id);

//Creates liked list
List * createList();

//Reviews the identifiers in linked list
void identifiers( List * list, ID *id);

//New node into linked list
int insertNewNode( List * list, Node * node);

//Search linked list for node
int listSearch(const List * list, Node * node);

//Puts node at front of the list
int insertAtFirst( List * list, int s_result);

#endif
