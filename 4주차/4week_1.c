#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//배열과 포인터 관계 121p

float trunc_sum(float *data);

void main() {
	float xarray[10], fsum = 0.0;
	int i;
	printf("Enter 10 reals: ");
	for (i = 0; i < 10; i++) {
		scanf("%f", xarray + i);
		fsum = fsum + *(xarray + i);
	}
	printf("Sum = %.2f \n", fsum);
	printf("Truncation Value = %.2f \n", trunc_sum(xarray)); //함수 호출
}

float trunc_sum(float data[]) {
	float sum = 0.0;
	int i, ivalue;
	for (i = 0; i < 10; i++) {
		ivalue = data[i];
		sum += (data[i] - ivalue);
	}
	return sum;
}
