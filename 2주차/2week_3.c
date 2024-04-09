#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//40명 학생의 평균을 구하기

void main()
{
	int i, sum, avg;
	int data[40];

	printf("40명의 학생의 성적을 입력해주세요 \n");
	for (i = 0; i < 40; i++) {
		scanf(" %d", &data[i]);
		sum += data[i];
	}
	avg = sum / 40;
	printf("평균은 %d 입니.", avg);
}