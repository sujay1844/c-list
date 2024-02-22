#ifndef LIST_H
#define LIST_H

typedef struct List {
	int length;
	int max;
	int *arr;
} List;

int append(List *list, int x);
List createList();
void printList(List list);
void deleteList(List list);

#endif // DEBUG
