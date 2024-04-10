//내림차순, 오른차순, 출력 함수 작성해서 배열크기와 데이터값 입력받고 출력하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 100

//오름차순 함수
void upstep_selection_sore(int list[], int n) {
	int s, m, j;
	int temp;

	for (s = 0; s < n-1; s++) {
		m = s;
		for (j = s + 1; j < n ; j++) 
			if (list[j] < list[m]) m = j;
		temp = list[s];
		list[s] = list[m];
		list[m] = temp;
	}
}

//내림차순 함수
void downstep_selection_sore(int list[], int n) {
	int s, m, j;
	int temp;

	for (s = 0; s < n - 1; s++) {
		m = s;
		for (j = s + 1; j < n; j++)
			if (list[j] > list[m]) m = j;
		temp = list[m];
		list[m] = list[s];
		list[s] = temp;
	}
}

//출력 함수
void print_data(int list[], int n) {
	int i;

	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

void main() {
	int list[N], n;
	int i;

	printf("데이터 수를 입력하세요 : ");
	scanf("%d", &n);

	printf("\n 데이터를 입력하세요 : ");

	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}

	printf("받은 데이터 : ");
	print_data(list, n);

	upstep_selection_sore(list, n);
	printf("오름차순 출력 : ");
	print_data(list, n);

	downstep_selection_sore(list, n);
	printf("내림차순 출력 : ");
	print_data(list, n);

}