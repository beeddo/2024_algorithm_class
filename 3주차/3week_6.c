#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int size = 0;
	int max = 0;
	int num = 0;

	printf("데이터를 입력해주세요 \n");
	scanf("%d", &num);

	while (num > 0) {
		size++;
		if (num > max) max = num;
		scanf(" %d", &num);
	}

	if (size == 0)
		printf("No data!");
	else
		printf("최대값은 %d, 데이터 수는 %d 입니다.", max, size);
}