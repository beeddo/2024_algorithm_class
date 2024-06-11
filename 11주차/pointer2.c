#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main() {
	int* p, q;
	float* fp, x;
	p = &q;
	*p = 199;
	fp = &x;  //포인터 값 초기화
	scanf("%f", fp);
	x = *fp;
	printf("%d---%.2f\n", q, x);
}