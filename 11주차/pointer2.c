#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main() {
	int* p, q;
	float* fp, x;
	p = &q;
	*p = 199;
	fp = &x;  //������ �� �ʱ�ȭ
	scanf("%f", fp);
	x = *fp;
	printf("%d---%.2f\n", q, x);
}