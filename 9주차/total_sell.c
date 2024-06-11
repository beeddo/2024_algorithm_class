#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM 500
#include <stdio.h>

long stocksum(long s[][2], int n);
long lookup(long pdb[][2], int n, long item_code);
void display_code(long pdb[][2], int n);

void main(int argc, char* argv[]) {
	FILE* pricedb;
	long pdb[MAX_NUM][2], item_code, item_price, item_sell;
	int i = 0, k = 0,n, total_sum = 0;

	if ((pricedb = fopen(argv[1], "r")) == NULL) {
		printf("데이터 파일을 열 수 없습니다. \n");
		exit(1);
	}

	while (fscanf(pricedb, "%ld %ld", &(pdb[i][0]),&(pdb[i][1]))!=EOF)
	{
		i++;
	}
	n = i;
	display_code(pdb, n);

	while (k < 3)
	{
		printf("물품코드와 팔린 개수를 입력하세요 : ");
		scanf(" %ld %ld", &item_code, &item_sell);

		item_price = lookup(pdb, n, item_code);

		if (item_price == 0)
			printf("%ld : 입력한 물품에 대한 가격 정보가 없습니다\n", item_code);
		else
			printf("%ld : %ld \n", item_code, item_price);

		total_sum += item_sell * item_price;
		item_code = 0;
		k++;
	}
	
	printf("오늘 판매 금액 정산 = %d\n", total_sum);
}

long lookup(long pdb[][2], int n, long item_code) {
	int i;

	for (i = 0; i < n; i++)
		if (pdb[i][0] == item_code)
			return pdb[i][1];
	return 0;
}

void display_code(long pdb[][2], int n) {
	int i;
	printf("물품코드 리스트 : \n");
	for (i = 0; i < n; i++)
		printf("%ld %ld\n", pdb[i][0], pdb[i][1]);
}
