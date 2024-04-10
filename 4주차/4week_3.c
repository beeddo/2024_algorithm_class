#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DNUM 100

int pcount(int a[], int n);
double avg(int a[], int n);
int large(int a[], int n);
int small(int a[], int n);

main() {
	int data[DNUM], k, n;
	printf("ó���� �������� �� :");
	scanf("%d", &n);

	printf("%d���� ������ �Է��ϼ���", n);
	for (k = 0; k < n; k++) {
		scanf("%d", &data[k]);
	}

	printf("���� ������ %d \n", pcount(data, n));
	printf("������ ����� %.2f \n", avg(data, n));
	printf("�ִ밪�� %d \n", large(data, n));
	printf("�ּҰ��� %d \n", small(data, n));

}

int pcount(int a[], int n)
{
	int j, result = 0;
	for (j = 0; j < n; j++) {
		if (a[j] % 2 == 0) result++;
	}
	return result;
}

double avg(int a[], int n) {
	int iavg = a[0], i, sum = 0;
	for (i = 0; i < n; i++) {
		sum = sum + a[i];
	}
	iavg = sum / n;
	return iavg;
}

int large(int a[], int n) {
	int imax = a[0], i;
	for (i = 1; i < n; i++) {
		if (a[i] > imax)imax = a[i];
	}
	return imax;
}

int small(int a[], int n) {
	int imin = a[0], i;
	for (i = 1; i < n; i++) {
		if (a[i] < imin)imin = a[i];
	}
	return imin;
}