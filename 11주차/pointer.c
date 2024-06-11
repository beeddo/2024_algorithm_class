#include <stdio.h>

main() {
	int* p, q;
	q = 100;
	p = &q;
	printf("%d", *p);
}