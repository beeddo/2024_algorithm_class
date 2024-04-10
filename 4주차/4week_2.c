//함수 호출 시 배열을 파라매터로 넘겨주기
//배열은 같은 형의 데이터 모임, 배열 이름을 넘겨준다, 배열 이름은 배열의 첫 데이터 주소 data = &data[0]
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
	printf("양의 갯수는 %d \n", pcount(data));
}
