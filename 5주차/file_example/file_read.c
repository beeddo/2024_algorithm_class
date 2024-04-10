//main()의 명령인수 받아들이기 =컴파일러마다 다르다, 프로젝트명에서 오른쪽버튼, 속성, 디버깅, 명령인수로 준다


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y);

main(int argc, char* argv[]) {
	int a, b, result, answer;
	int correct = 0, i = 0;

	FILE *infile;
	FILE* out;

	if (argc != 3) {
		printf("실행인수를 잘못 주었습니다 \n");
		exit(1);
	}

	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("입력 파일을 열 수 없습니다. \n");
		exit(1);
	}

	if ((out = fopen(argv[2], "w")) == NULL) {
		printf("출력 파일을 만들 수 없습니다. \n");
		exit(1);
	}

	while (fscanf(infile, "%d %d", &a, &b) != EOF) {
		printf("%d : gcd(%d %d)=", i + 1, a, b);
		scanf("%d", &answer);
		result = gcd(a, b);

		if (answer != result){
			printf("Answer : gcd(% d % d) = % d \n", a, b, result);
			fprintf(out, "%d %d \n", a, b); //파일 저장
		}

		else {
			printf("Correct \n");
			correct++;
		}
		i++;
	}
	printf("%d 문제 중에서 %d 문제 통과하셨습니다 \n", i, correct);
}

int gcd(int a, int b) {
	if (b == 0)return a;
	else return gcd(b, a % b);
}
//주로 main 함수의 인수는 그 프로그램의 실행을 위한 입출력파일을 지정할 때 많이 사용한다