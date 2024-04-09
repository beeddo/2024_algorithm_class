#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int a,b,c ;
	char op;

	printf("숫자 2개를 입력해주세요\n");
	scanf("%d %d", &a,&b);
	printf("연산자를 입력해주세요\n");
	scanf(" %c", &op); //앞서 입력받은 값으로 인해 버퍼에 남아있는 쓰레기 값 지우기=>앞에 띄어쓰기

	if(op == '+') c = a + b;
	if(op == '-') c = a - b;
	if(op == '*') c = a * b;
	if(op == '/') c = a / b;

	printf("결과값은 %d 입니다.\n",c);
}