#define _CRT_SECURE_NO_WARNINGS
#define	NUM 100
#include <stdio.h>

//const와 define의 차이? define은 오류가 명확하게 뜨지 않음
void main() {
	int i, sid, Jumsu, rank, n;
	int scores[NUM][2];

	printf("학생 수를 입력해주세요 : \n");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("학생의 id와 점수를 입력해주세요 \n");
		scanf(" %d %d", &scores[i][0], &scores[i][1]);
	}

	printf("찾으려는 학생의 id를 입력해주세요. \n");
	scanf(" %d", &sid);
	for (i = 0; i < n; i++) {
		if (sid == scores[i][0]) {
			Jumsu = scores[i][1];
			break;
		}
	}

	rank = 0;
	for (i = 0; i < n; i++) {
		if (scores[i][1] > Jumsu) rank++;
	}

	printf("%d 번의 점수 : %d \n", sid, Jumsu);
	printf("%d 번의 등수 : %d \n", sid, rank + 1);
}