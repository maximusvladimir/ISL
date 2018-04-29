#include <stdlib.h>

typedef struct ListHead {
	struct List* next;
	int length;
	int val;
} ListHead;

typedef struct List {
	struct List* next;
	int val;
} List;

ListHead* Add(ListHead* root, int val) {
	List* neu = (List*)malloc(sizeof(List));
	neu->val = val;
	neu->next = NULL;
	
	if (root->next == NULL) {
		root->next = neu;
	} else {
		List* n = root->next;
		List* prev = NULL;
		while (n != NULL) {
			prev = n;
			n = n->next;
		}
		prev->next = neu;
	}

	root->length++;
	
	return root;
}

int Get(ListHead* l, int index) {
	if (index == 0) {
		return l->val;
	}

	List* curr = l->next;
	int i = 0;
	while (curr != NULL) {
		if (i == index) {
			return curr->val;
		}
		curr = curr->next;
		i++;
	}
}

int main(int argc, char* argv[]) {
	ListHead* start = (ListHead*)malloc(sizeof(ListHead));
	start = Add(start, 1);
	start = Add(start, 2);
	start = Add(start, 3);
	start = Add(start, 4);
	start = Add(start, 5);

	int item = Get(start, 3);

	printf("%d\n", item);

	return 0;	
}
