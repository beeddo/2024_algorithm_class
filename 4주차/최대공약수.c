#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b);

void main()
{
	int result;
	int a, b, cond = 1;

	while (cond) {
		printf("최대공약수를 구할 두 수를 입력 하세요");
		scanf("%d %d", &a, &b); 
		result = gcd(a, b);
		printf("gcd(%d, %d)= %d \n\n", a, b, result);
		printf("계속하실래요?(1/0)");
		scanf("%d", &cond);
	}
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
