#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int append(List *list, int x) {
	// Check if the list has enough capacity
	if (list->length >= list->max) {

		// If not, double the capacity
		list->max *= 2;

		int *newArr = realloc(list->arr, list->max * sizeof(int));
		if (newArr == NULL) {
			fprintf(stderr, "Memory reallocation failed\n");
			return -1;
		} else {
			list->arr = newArr;
		}
	}

	// Add the new element to the end of the list
	list->arr[list->length] = x;

	// Increment the length of the list
	list->length++;

	return 0;
}

List createList() {
    List list;

	list.length = 0;
	list.max = 2; // Initial capacity

	list.arr = malloc(list.max * sizeof(int));
	if (list.arr == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
	}

	return list;
}

void printList(List list) {
	for (int i = 0; i < list.length; ++i) {
		printf("%d ", list.arr[i]);
	}
	printf("\n");
}

void deleteList(List list) {
	free(list.arr);
}
