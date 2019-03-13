
#include <stdlib.h>
#include <stdio.h>
#ifndef H_LIST
#define H_LIST

// Define a node structure with all its components
struct Node {
    int key;
    int value;
    struct Node *next;
};

typedef struct Node Node;

// Define a linked-list of nodes each with components and next pointers
struct linked_list {
    Node *top;
    int size;
};

typedef struct linked_list List;

//New node
Node * createNode(int key, int value);

//Creates list
List * create_new_list();

void display(List * pList);

void count_indentifiers(List * pList, int key);

//Insert new node into front of list list
int insert_new_node(List * list, Node * node);

//Searchs for an element in the list
int search(const List * list, Node * node);

//Moves element to front of list
int to_front(List * list, int s_result);

#endif

