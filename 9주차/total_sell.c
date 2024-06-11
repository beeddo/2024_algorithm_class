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
		printf("������ ������ �� �� �����ϴ�. \n");
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
		printf("��ǰ�ڵ�� �ȸ� ������ �Է��ϼ��� : ");
		scanf(" %ld %ld", &item_code, &item_sell);

		item_price = lookup(pdb, n, item_code);

		if (item_price == 0)
			printf("%ld : �Է��� ��ǰ�� ���� ���� ������ �����ϴ�\n", item_code);
		else
			printf("%ld : %ld \n", item_code, item_price);

		total_sum += item_sell * item_price;
		item_code = 0;
		k++;
	}
	
	printf("���� �Ǹ� �ݾ� ���� = %d\n", total_sum);
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
	printf("��ǰ�ڵ� ����Ʈ : \n");
	for (i = 0; i < n; i++)
		printf("%ld %ld\n", pdb[i][0], pdb[i][1]);
}
