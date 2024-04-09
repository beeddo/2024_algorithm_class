#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int n, data, large = 0;
	int count = 0;

	printf("자료의 개수를 입력해주세요 \n");
	scanf(" %d", &n);


	do {
		printf("데이터를 입력해주세요 \n");
		scanf(" %d", &data);

		if (data > large) large = data;
		count = count + 1;
	} while (count < n);

	printf("가장 큰 수는 %d 입니다.", large);
}