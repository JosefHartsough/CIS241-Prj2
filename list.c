// list.c

#include"list.h"

//New node
Node * createNode(int key, int value) {
    Node *pNode = malloc(sizeof(Node *));
    pNode->key = key;
    pNode->value = value;
    pNode->next = 0;
}

//Creates list
List * create_new_list() {
    List *pList = malloc( sizeof(List));
    pList->top = 0;
    pList->size = 0;
    return pList;
}

void display(List * pList) {
    if (pList == 0) return;
    if (pList->top == 0) return;
    Node *pNode = pList->top;
    while (pNode != 0) {
        printf("key: %d, value %d\n", pNode->key, pNode->value);
        pNode = pNode->next;
    }
}

void count_identifiers(List * list, int key) {

}

//Insert new node into front of list list
int insert_new_node(List * pList, Node * pNewNode) {
    Node *pNode = pList->top;
    pList->top = pNewNode;
    pNewNode->next = pNode;
    pList->size++;
    return pList->size;
}

//Searchs for an element in the list
int search(const List * list, Node * node) {
}

//Moves element to front of list
int to_front(List * list, int s_result) {

}