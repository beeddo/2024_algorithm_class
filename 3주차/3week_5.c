#define _CRT_SECURE_NO_WARNINGS
#define DMAX 100
#include <stdio.h>

void main() {
	int n, i, scores[DMAX], sum, over_count;
	double avg;
	sum = 0;
	over_count = 0;

	printf("학생 수를 입력하세요 \n");
	scanf("%d", &n);

	printf("점수를 입력해주세요 \n");
	for (i = 0; i < n; i++) {
		scanf(" %d", &scores[i]);
		sum = sum + scores[i];
	}

	avg = (double)sum / n;

	printf("평균은 %f 입니다\n", avg);
	for (i = 0; i < n; i++) {
		if (scores[i] > avg) over_count++;
	}
	printf("평균 이상의 점수는 %d개 입니다.", over_count);

}