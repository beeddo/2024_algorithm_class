#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int n1, n2, n3, large;

	printf("세 수를 입력하세요. \n");
	scanf("%d %d %d", &n1, &n2, &n3);

	if (n1 > n2) large = n1;
	else large = n2;

	if (n3 > large) large = n3;

	printf("가장 큰 수는 %d 입니다.", large);
}