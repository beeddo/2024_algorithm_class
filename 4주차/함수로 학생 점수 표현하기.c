#define _CRT_SECURE_NO_WARNINGS
#define	NUM 100
#include <stdio.h>

//const�� define�� ����? define�� ������ ��Ȯ�ϰ� ���� ����
int find_avg(int sdata[][2], int n);
int find_avg(int sdata[][2], int n);
int find_rank(int sdata[][2], int n, int sid);

void main() {
	int i, sid, Jumsu, rank, n;
	int scores[NUM][2];

	printf("�л� ���� �Է����ּ��� :");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("�л��� id�� ������ �Է����ּ��� \n");
		scanf(" %d %d", &scores[i][0], &scores[i][1]);
	}


	printf("��� : %d \n", find_avg(scores, n));
	printf("�ִ밪 : %d \n", find_max(scores, n));

	printf("ã������ �л��� id�� �Է����ּ���. \n");
	scanf(" %d", &sid);
	printf("%d�� �л��� ���: %d", sid, find_rank(scores, n, sid));
}

int find_avg(int sdata[][2], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + sdata[i][1];
	return sum / n;
}

int find_max(int sdata[][2], int n) {
	int max = sdata[0][1];
	for (int i = 0; i < n; i++)
		if (sdata[i][1] > max)
			max = sdata[i][1];
	return max;
}

int find_rank(int sdata[][2], int n, int sid) {
	int jumsu = 0;
	int rank = 0;

	for (int i = 0; i < n; i++) {
		if (sid == sdata[i][0]) {
			jumsu = sdata[i][1];
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (sdata[i][1] > jumsu)
			rank = rank + 1;
	}
	return rank + 1;
}#define _CRT_SECURE_NO_WARNINGS
#define	NUM 100
#include <stdio.h>

//const�� define�� ����? define�� ������ ��Ȯ�ϰ� ���� ����
int find_avg(int sdata[][2], int n);
int find_avg(int sdata[][2], int n);
int find_rank(int sdata[][2], int n, int sid);

void main() {
	int i, sid, Jumsu, rank, n;
	int scores[NUM][2];

	printf("�л� ���� �Է����ּ��� :");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("�л��� id�� ������ �Է����ּ��� \n");
		scanf(" %d %d", &scores[i][0], &scores[i][1]);
	}


	printf("��� : %d \n", find_avg(scores, n));
	printf("�ִ밪 : %d \n", find_max(scores, n));

	printf("ã������ �л��� id�� �Է����ּ���. \n");
	scanf(" %d", &sid);
	printf("%d�� �л��� ���: %d", sid, find_rank(scores, n, sid));
}

int find_avg(int sdata[][2], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + sdata[i][1];
	return sum / n;
}

int find_max(int sdata[][2], int n) {
	int max = sdata[0][1];
	for (int i = 0; i < n; i++)
		if (sdata[i][1] > max)
			max = sdata[i][1];
	return max;
}

int find_rank(int sdata[][2], int n, int sid) {
	int jumsu = 0;
	int rank = 0;

	for (int i = 0; i < n; i++) {
		if (sid == sdata[i][0]) {
			jumsu = sdata[i][1];
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (sdata[i][1] > jumsu)
			rank = rank + 1;
	}
	return rank + 1;
}