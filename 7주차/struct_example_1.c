#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct member {
	int id;
	char name[20];
	float score;
} example;


void over40(example* a, int n);
example find_max(example* a, int n);

main() {
	example onep, exmember[20];
	int i, n;
	printf("데이터 수를 입력해주세요 : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("데이터를 입력해주세요 :");
		scanf("%d %s %f", &exmember[i].id, &exmember[i].name, &exmember[i].score);
	}
	over40(exmember, n);
	onep = find_max(exmember, n);
	printf("가장 높은 학생 = %d : %s : %.2f\n", onep.id, onep.name, onep.score);
}

void over40(example a[], int n) {
	int i;
	printf("4.0이상의 점수를 받은 학생 : \n");

	for (i = 0; i < n; i++) {
		if (a[i].score >= 4.0) printf("%d : %s : %.2f\n", a[i].id, a[i].name,a[i].score);
	}
}

example find_max(example a[], int n) {
	int i, max_index = 0;
	
	for (i = 0; i < n; i++) {
		if (a[i].score > a[max_index].score) max_index = i;
	}

	return a[max_index];
}
