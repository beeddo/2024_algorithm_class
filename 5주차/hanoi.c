//재귀 알고리즘-하노이탑 문제

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n, char a, char c, char b) {
	if (n == 1) printf("원반을 %c 에서 %c 로 옮기세요\n", a, c);
	else {
		hanoi(n - 1, a, b, c);
		hanoi(1, a, c, b);
		hanoi(n - 1, b, c, a);

	}
}

void main() {
	int n;

	printf("원반의 갯수를 입력해 주세요 : \n");
	scanf("%d", &n);

	if (n <= 0) {
		printf("양수의 값을 입력해주세요 \n");
	}
	else
	{
		hanoi(n, 'a', 'b', 'c');
	}
}
