#include <stdio.h>
#include "list.h"
#include <string.h>


int main()
{
    int size;
    Node *pNode;
    List *pList = create_new_list();

    pNode = createNode(1, 10);
    size = insert_new_node(pList, pNode);
    printf("%d\n", size);
    display(pList);

    pNode = createNode(2, 20);
    size = insert_new_node(pList, pNode);
    printf("%d\n", size);
    display(pList);
}
