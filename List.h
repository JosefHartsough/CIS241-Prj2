#include <stdio.h>




int vending_start(char data[]);

void vending_menu();

item* add_to_front(item* head);

item* create(item* next);

item* delete(item *l, item *node);

void showList(item *head);

int Load(char inf[], item **l);

int Save(char outf[], item *l);

float Buy(item *l, float q);

void Price(item *l, char p[]);

item* findItem(item *l, char p[]);

int doesItemExist(item* head, char p[]);

*/




