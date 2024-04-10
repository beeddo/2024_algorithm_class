#define _CRT_SECURE_NO_WARNINGS
#define	NUM 100
#include <stdio.h>

//const와 define의 차이? define은 오류가 명확하게 뜨지 않음
int find_avg(int sdata[][2], int n);
int find_avg(int sdata[][2], int n);
int find_rank(int sdata[][2], int n, int sid);

void main() {
	int i, sid, Jumsu, rank, n;
	int scores[NUM][2];

	printf("학생 수를 입력해주세요 :");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("학생의 id와 점수를 입력해주세요 \n");
		scanf(" %d %d", &scores[i][0], &scores[i][1]);
	}


	printf("평균 : %d \n", find_avg(scores, n));
	printf("최대값 : %d \n", find_max(scores, n));

	printf("찾으려는 학생의 id를 입력해주세요. \n");
	scanf(" %d", &sid);
	printf("%d번 학생의 등수: %d", sid, find_rank(scores, n, sid));
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

//const와 define의 차이? define은 오류가 명확하게 뜨지 않음
int find_avg(int sdata[][2], int n);
int find_avg(int sdata[][2], int n);
int find_rank(int sdata[][2], int n, int sid);

void main() {
	int i, sid, Jumsu, rank, n;
	int scores[NUM][2];

	printf("학생 수를 입력해주세요 :");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("학생의 id와 점수를 입력해주세요 \n");
		scanf(" %d %d", &scores[i][0], &scores[i][1]);
	}


	printf("평균 : %d \n", find_avg(scores, n));
	printf("최대값 : %d \n", find_max(scores, n));

	printf("찾으려는 학생의 id를 입력해주세요. \n");
	scanf(" %d", &sid);
	printf("%d번 학생의 등수: %d", sid, find_rank(scores, n, sid));
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