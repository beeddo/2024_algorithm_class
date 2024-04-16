#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char compare(int x, int y);
int bsearch(int a[], int n, int key);
void selection_sort(int a[], int n);
void print_function(int a[], int n);

void main() {
	int list[] = { 10, 120, 30, 40, 5, 90, 77, 25, 45, 100 };
	int n = sizeof(list) / sizeof(int);
	int key,i;
	char sorted;

	print_function(list, n);
	printf("데이터가 정렬되어 있나요? (y/n) ");
	scanf("%c", &sorted);

	if (sorted == 'n') {
		selection_sort(list, n);
		printf("list를 정렬했습니다. \n");
		print_function(list, n);
	}
	printf("찾으려는 값을 입력해주세요 ");
	scanf("%d", &key);

	if ((i = bsearch(list, n, key)) != -1) {
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
		switch (compare(key,a[mid]))
		{
		case '>' :
			left = mid + 1;
			break;
		case '<' :
			right = mid - 1;
			break;
		case '=' :
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

void selection_sort(int a[], int n) {
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

void print_function(int a[], int n) {
	printf("list : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
