#include <stdlib.h>
#include <stdio.h>
#ifndef H_LIST
#define H_LIST

typedef char * Name;
typedef int amount;

// Define a node structure with all its components
struct Nodes{
    Name name;
    amount count;
    struct Nodes * next;
};

typedef struct Nodes Node;


// Define a linked-list of nodes each with components and next pointers
struct linked_list {
    Node *top;
    int size;
};

typedef struct linked_list List;

//New node and put into list
Node * New_Node(Name * id);

//Creates list
List * create_new_list();


void process( List * list, Name *id);

//Insert new node into list
int insert_new_node( List * list, Node * node);

//Searchs for an element in the list
int search(const List * list, Node * node);

//Moves element to front of list
int to_front( List * list, int s_result);

#endif