#include <stdio.h>

extern void dum();

void call() {
	dum();
	printf("hello world\n");
}

int main() {
	call();
	return 0;
}
