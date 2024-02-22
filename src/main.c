#include "list.h"

int main() {
	List list = createList();

	append(&list, 10);
	append(&list, 20);
	append(&list, 30);
	append(&list, 40);
	append(&list, 50);
	append(&list, 60);
	append(&list, 70);
	append(&list, 80);
	append(&list, 90);
	append(&list, 100);

	printList(list);
	deleteList(list);

	return 0;
}
