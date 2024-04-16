#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM 100

char compare(int x, int y);
int bsearch(int a[], int n, int key);
int reburse_search(int a[], int n, int key);
void upstep_selection_sort(int a[], int n);
void downstep_selection_sort(int a[], int n);
void print_function(int a[], int n);
void input_function(int a[], int n);

void main() {
	int list[NUM];
	int n = 0;
	int key, i;
	int sorted;

	printf("데이터 수를 입력해주세요 : ");
	scanf("%d", &n);

	printf("데이터를 입력해주세요 : ");
	input_function(list, n);
	print_function(list, n);

	printf("오름차순 >> 1 | 내림차순 >> 2 : ");
	scanf("%d", &sorted);

	if (sorted == 1) {
		upstep_selection_sort(list, n);
		printf("오름차순으로 list를 정렬했습니다. \n");
		print_function(list, n);
	}
	else {
		downstep_selection_sort(list, n);
		printf("내림차순으로 list를 정렬했습니다. \n");
		print_function(list, n);
	}
	printf("찾으려는 값을 입력해주세요 ");
	scanf("%d", &key);

	if (sorted == 1 && (i = bsearch(list, n, key)) != -1) {
		printf("%d는 %d번째에 있습니다.", key, i + 1);
	}
	else if (sorted == 2 && (i = reburse_bsearch(list, n, key)) != -1) {
		printf("%d는 %d번째에 있습니다.", key, i + 1);
	}
	else
		printf("%d는 존재하지 않습니다.", key);
}

int bsearch(int a[], int n, int key) {
	int mid;
	int left = 0, right = n - 1;

	while (left <= right) {
		mid = (left + right) / 2;
		switch (compare(key, a[mid]))
		{
		case '>':
			left = mid + 1;
			break;
		case '<':
			right = mid - 1;
			break;
		case '=':
			return mid;
		}
	}

	return -1;
}

int reburse_bsearch(int a[], int n, int key) {
	int mid;
	int left = 0, right = n - 1;

	while (left <= right) {
		mid = (left + right) / 2;
		switch (compare(key, a[mid]))
		{
		case '>':
			right = mid - 1;
			break;
		case '<':
			left = mid + 1;
			break;
		case '=':
			return mid;
		}
	}

	return -1;
}

char compare(int x, int y) {
	if (x > y) return '>';
	else if (x < y) return '<';
	else return '=';
}

void upstep_selection_sort(int a[], int n) {
	int s, m, j;
	int temp;

	for (s = 0; s < n - 1; s++)
	{
		m = s;
		for (j = s + 1; j < n; j++) {
			if (a[j] < a[m]) m = j;
		}
		temp = a[m];
		a[m] = a[s];
		a[s] = temp;
	}
}

void downstep_selection_sort(int a[], int n) {
	int s, m, j;
	int temp;

	for (s = 0; s < n - 1; s++)
	{
		m = s;
		for (j = s + 1; j < n; j++) {
			if (a[j] > a[m]) m = j;
		}
		temp = a[m];
		a[m] = a[s];
		a[s] = temp;
	}
}

void print_function(int a[], int n) {
	printf("list : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void input_function(int a[], int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
