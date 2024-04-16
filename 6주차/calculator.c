#define STAGE1 0
#define STAGE2 1
#define STAGE3 2
#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

void int_calculator(void);
int int_operation(char op, int op1, int op2);
int get_int(int current_operand, char c);
int is_operator(char c);
int is_digit(char c);

void main() {
	printf("계산기 프로그램을 시작합니다. \n");
	printf("정수형의 피연산자와 사칙연산자 중 하나를 입력하시오. \n");
	printf("결과를 받은 후 끝내려면 문자 x를 입력하시오 \n");
	int_calculator();
	printf("\n계산기 프로그램을 종료합니다. \n");
}

void int_calculator(void) {
	int operand1 = 0, operand2 = 0;
	char op, c = '0';
	int result;
	int current_stage = STAGE1;

	while (c != 'x') {
		c = getchar();
		if (current_stage == STAGE1) {
			if (is_digit(c))
				operand1 = get_int(operand1, c);
			else if (is_operator(c)) {
				op = c;
				current_stage = STAGE2;
				operand2 = 0;
			}
		}
		else if (current_stage == STAGE2) {
			if (is_digit(c))
				operand2 = get_int(operand2, c);
			else if(c == '\n')
			{
				result = int_operation(op, operand1, operand2);
				printf("= %d", result);
				current_stage = STAGE3;
			}
		}
		else if (current_stage == STAGE3) {
			if (c == '\n') {
				operand1 = 0;
				current_stage = STAGE1;
			}
			else if (is_operator(c)) {
				op = c;
				current_stage = STAGE2;
				operand1 = result;
				operand2 = 0;
			}
		}
	}
}

int int_operation(char op, int operand1, int operand2) {
	int result;

	switch (op) {
	case '+':
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	case '*':
		result = operand1 * operand2;
		break;
	case '/':
		if (operand2 == 0) {
			printf("\n0으로 나눌 수 없습니다.\n");
			result = operand1;
		}
		else
		{
			result = operand1 / operand2;
			break;
		}
	case '^':
		result = pow(operand1, operand2);
		break;
	}
	return result;
}

int get_int(int current_operand, char c) {
	int new_value;

	new_value = c - '0';
	current_operand *= 10; 
	current_operand += new_value;
	return current_operand;
}

int is_operator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return 1;
	else
		return 0;
}

int is_digit(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}
