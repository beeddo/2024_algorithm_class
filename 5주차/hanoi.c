//��� �˰���-�ϳ���ž ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n, char a, char c, char b) {
	if (n == 1) printf("������ %c ���� %c �� �ű⼼��\n", a, c);
	else {
		hanoi(n - 1, a, b, c);
		hanoi(1, a, c, b);
		hanoi(n - 1, b, c, a);

	}
}

void main() {
	int n;

	printf("������ ������ �Է��� �ּ��� : \n");
	scanf("%d", &n);

	if (n <= 0) {
		printf("����� ���� �Է����ּ��� \n");
	}
	else
	{
		hanoi(n, 'a', 'b', 'c');
	}
}
