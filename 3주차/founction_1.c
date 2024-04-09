#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_pow(int x, int y); //함수 선언
void main() {
	int k;

	for (k = 2; k < 6; k++) {
		printf("%d ** %d = %d \n", k, k + 1, my_pow(k, k + 1)); //함수 호출
	}
}
//함수 작성
int my_pow(int x, int y) {
	int i, ans = 1;

	for (i = 0; i < y; i++)
		ans = ans + x;
	return ans
}