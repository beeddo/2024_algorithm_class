#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 15
#include <stdio.h>

void make_msquare(int table[][MAX_SIZE], int n);
void display(int table[][MAX_SIZE], int n);

void main() {
	int n;
	int table[MAX_SIZE][MAX_SIZE];

	printf("마방진의 크기를 입력해주세요 : ");
	scanf("%d", &n);

	if ((n<1 || n>MAX_SIZE)) {
		printf("최대 크기는 15입니다.");
		exit(0);
	}
	if (!(n % 2)) {
		printf("홀수만 입력 가능합니다.");
		exit(0);
	}

	make_msquare(table, n);
	display(table, n);

}

void make_msquare(int table[][MAX_SIZE], int n) {

	int digit,r,c,row,col;

	for (r = 0; r < n; r++) {
		for (c = 0; c < n; c++) {
			table[r][c] = 0;
		}
	}
	r = 0; c = (n - 1) / 2;
	table[r][c] = 1;

	for (digit = 2; digit <= n * n; digit++) {
		row = r - 1;
		col = c - 1;
		if (row < 0) row = n - 1;
		if (col < 0) col = n - 1;
		if (table[row][col]) r++;
		else {
			r = row;
			c = col;
		}
		table[r][c] = digit;
	}
}
void display(int table[][MAX_SIZE], int n) {
	int r, c, sum = 0;

	for (r = 0; r < n; r++) {
		for (c = 0; c < n; c++) {
			printf(" % 5d", table[r][c]);
		}
		printf("\n");
	}
	for (c = 0; c < n; c++) {
		sum += table[0][c];
	}

	printf("row/column/diagonal sum = %d\n", sum);
}