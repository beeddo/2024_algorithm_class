//�Լ� ȣ�� �� �迭�� �Ķ���ͷ� �Ѱ��ֱ�
//�迭�� ���� ���� ������ ����, �迭 �̸��� �Ѱ��ش�, �迭 �̸��� �迭�� ù ������ �ּ� data = &data[0]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int pcount(int a[])
{
	int j, result = 0;
	for (j = 0; j < 10; j++) {
		if (a[j] > 0) result++;
	}
	return result;
}
main() {
	int data[10], k;

	printf("Enter 10 data : ");
	for (k = 0; k < 10; k++) {
		scanf("%d", &data[k]);
	}
	printf("���� ������ %d \n", pcount(data));
}
