#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int num, r;

	printf("숫자를 입력해주세요 \n");
	scanf("%d", &num);

	while (num > 0)
	{
		r = num % 10;
		num = num / 10;
		printf("%d ", r);
	}
}