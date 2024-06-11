#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct student {
	long id;
	char name[20];
	double score;
}sdatatype;

void insert_sort1(sdatatype a[], int n);
void insert_sort2(sdatatype a[], int n);

void main(int argc, char* argv[]) {
	sdatatype s[50];
	FILE* infile, * out;
	int i = 0, j;
	char choice;

	if (argc != 3) {
		printf("실행 인수를 잘못 주었습니다. \n");
		exit(1);
	}

	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("입력 파일을 열 수 없습니다.\n");
		exit(1);
	}

	if ((out = fopen(argv[2], "w")) == NULL) {
		printf("결과 파일을 열 수 없습니다.\n");
		exit(1);
	}

	while (fscanf(infile, "%ld %s %lf", &(s[i].id), s[i].name, &(s[i].score)) != EOF) {
		i++;
	}

	printf("학번 순으로 저장하려면 1을 \n");
	printf("성적순으로 저장하려면 2를 선택하시오 : ");
	scanf("%c", &choice);
	
	if (choice == '1') insert_sort1(s, i);
	else if (choice == '2') insert_sort2(s, i);
	else {
		printf("선택번호를 잘못 입력하였습니다. \n");
		exit(1);
	}

	for (j = 0; j < i; j++) {
		fprintf(out, "%ld \t %s \t %.2f \n", (s[j].id), s[j].name, (s[j].score));
		printf("%ld \t %s \t %.2f \n", (s[j].id), s[j].name, (s[j].score));
	}
	printf("Program terminated ... \n");
}

//학번의 오름차순으로 정렬
void insert_sort1(sdatatype a[], int n) {
	int i, j;
	sdatatype temp;
	for (i = 1; i <= n - 1; i++) {
		temp = a[i];
		j = i - 1;
		while (a[j].id > temp.id && j >= 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

// 학점이 큰 값부터 내림차순으로 정렬
void insert_sort2(sdatatype a[], int n) {
	int i, j;
	sdatatype temp;
	for (i = 1; i < n - 1; i++) {
		temp = a[i];
		j = i - 1;
		while (a[j].score < temp.score && j >= 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}