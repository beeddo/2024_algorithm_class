#define NUM 20
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//0.00~ 99.99 사이의 실수 난수를 20개 만들어 소수 부분의 합과 정수 부분의 합을 구하시오
int main() {
	float rdata[NUM], fsum = 0.0;
	int i, isum = 0, temp;

	srand((unsigned int)time(NULL)); //seed 값 설정

	for (i = 0; i < NUM; i++) {
		rdata[i] = rand() % 100 + rand() % 100 / 100.0; //난수를 생성해 rdata[]에 저장, 0~99,99
		printf("%.2f ", rdata[i]); //난수 출력
		if ((i + 1) % 7 == 0) printf("\n");
	}

	for (i = 0; i < NUM; i++) {
		temp = rdata[i]; //temp에 데이터를 넣음, temp는 정수형 변수이기 때문에 소수부분이 버려짐
		isum += temp; //정수 부분을 더해줌
		fsum += (rdata[i] - temp);  //원래의 데이터에서 정수부분은 뺀 값을 fsum에 더해줌
	}

	printf("\n\n정수부분의 합 : %d \n", isum);
	printf("\n소수부분의 합 : %.3f \n", fsum);

	system("pause");
}