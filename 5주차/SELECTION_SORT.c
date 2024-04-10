//��������, ��������, ��� �Լ� �ۼ��ؼ� �迭ũ��� �����Ͱ� �Է¹ް� ����ϱ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 100

//�������� �Լ�
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

//�������� �Լ�
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

//��� �Լ�
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

	printf("������ ���� �Է��ϼ��� : ");
	scanf("%d", &n);

	printf("\n �����͸� �Է��ϼ��� : ");

	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}

	printf("���� ������ : ");
	print_data(list, n);

	upstep_selection_sore(list, n);
	printf("�������� ��� : ");
	print_data(list, n);

	downstep_selection_sore(list, n);
	printf("�������� ��� : ");
	print_data(list, n);

}