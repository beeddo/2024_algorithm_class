#define NUM 20
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//0.00~ 99.99 ������ �Ǽ� ������ 20�� ����� �Ҽ� �κ��� �հ� ���� �κ��� ���� ���Ͻÿ�
int main() {
	float rdata[NUM], fsum = 0.0;
	int i, isum = 0, temp;

	srand((unsigned int)time(NULL)); //seed �� ����

	for (i = 0; i < NUM; i++) {
		rdata[i] = rand() % 100 + rand() % 100 / 100.0; //������ ������ rdata[]�� ����, 0~ 99.99
		printf("%.2f ", rdata[i]); //���� ���
		if ((i + 1) % 7 == 0) printf("\n");
	}

	for (i = 0; i < NUM; i++) {
		temp = rdata[i]; //temp�� �����͸� ����, temp�� ������ �����̱� ������ �Ҽ��κ��� ������
		isum += temp; //�����κ��� ������
		fsum += (rdata[i] - temp); //������ �����Ϳ��� �����κ��� �� ���� fsum�� ������
	}

	printf("\n\n�����κ��� �� : %d \n", isum);
	printf("\n�Ҽ��κ��� �� : %.3f \n", fsum);

	system("pause");
}