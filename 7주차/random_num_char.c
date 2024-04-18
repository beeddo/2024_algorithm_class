#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int i, num;
	char c;
	float f;

	srand((unsigned int)time(NULL));

	printf("기본 난수 생성\n");
	for (i = 0; i < 10; i++) {
		num = rand() % 101;
		printf("%d ", num);
	}

	printf("\n\n101~200사이의 난수 생성\n");
	for (i = 0; i < 10; i++) {
			num = (rand()%101+100);
			printf("%d ", num);
	}

	printf("\n\n알파벳 난수 생성\n");
	for (i = 0; i < 10; i++) {
		c = (char)('a'+rand()%26);
		printf("%c ", c);
	}

	printf("\n\n실수 난수 생성\n");
	for (i = 0; i < 10; i++) {
		f = rand() % 100 + rand() % 100 / 100.0;
		printf("%.2f ", f);
	}
}


//#define MAX 20
//char ch[MAX];
//int i, j;

//ch[0] = 'a' + rand() % 26;
//for (i = 1li < MAX; i++) {
//	ch[i] = 'a' + rand() % 26;
//	for (j = 0; j < i; j++) {
//		if (ch[i] == ch[j]) {
//			i = j;
//			break;
//		}
//	}
//} //for문으로 문자 출력하기
