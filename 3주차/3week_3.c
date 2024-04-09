#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int n, i, data;
	int allzero = 1;
	long mult = 1;

	printf("자료의 개수를 입력해주세요.\n");
	scanf("%d", &n);

	printf("%d 개의 숫자를 입력해주세요 : \n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &data);
		if (data != 0) {
			mult *= data;
			allzero = 0;
		}
	}
	if (allzero) mult = 0;
	printf("결과값은 %ld 입니다. \n", mult);
}