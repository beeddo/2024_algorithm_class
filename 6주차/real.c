//상태 전이 분석
#define STAGE1 0
#define STAGE2 1
#define STAGE3 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void real_calculator(void);
double real_operation(char op, double operand1, double operand2);
double get_real(double current_operand, char c, int status);
int is_operator(char c);
int is_digit(char c);
//double pow(double x, double y);

void main() {
    printf("계산기 프로그램을 시작합니다. \n");
    printf("실수형의 피연산자와 사칙연산자 중 하나를 입력하시오. \n");
    printf("결과를 받은 후 끝내려면 문자 x를 입력하시오 \n");
    real_calculator();
    printf("\n계산기 프로그램을 종료합니다. \n");
}

void real_calculator(void) {
    double operand1 = 0, operand2 = 0;
    char op, c; //c는 null
    double result;
    int current_stage = STAGE1, status = 0;

    while ((c = getchar()) != 'x') {
        if (current_stage == STAGE1) {
            if (is_digit(c)) {
                operand1 = get_real(operand1, c, status);
                if (status != 0) status++;
            }
            else if (is_operator(c)) {
                op = c;
                current_stage = STAGE2;
                status = 0;
                operand2 = 0;
            }
            else if (c == '.') status = 1; //소수
        }//STAGE1

        else if (current_stage == STAGE2) {
            if (is_digit(c)) {
                operand2 = get_real(operand2, c, status);
                if (status != 0) status++;
            }
            else if (c == '\n') {
                result = real_operation(op, operand1, operand2);
                printf("= %.3f", result);
                current_stage = STAGE3;
                status = 0;
            }
            else if (c == '.') status = 1;
        }//STAGE2

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
        }//STAGE3
    }
}

double real_operation(char op, double operand1, double operand2) {
    double result;

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

double get_real(double current_operand, char c, int status) {
    int part1; //status = 0일때
    double part2; //status = 1일때

    if (status == 0) {
        part1 = c - '0';
        current_operand *= 10; //10자리만큼 자리수 지정
        current_operand += part1;
    }
    else { //status가 0이 아닐때
        part2 = c - '0';
        part2 = part2 * pow(10, -status);//10의 -status승(-1, -2승 ,,,=0.1 , 0.01 ...)의 자리수
        current_operand += part2;
    }
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

//double pow(double x, double y) {
//    if (y == 0) return 1;
//    else if (y == 1)return x;
//    else if (y > 0) x * pow(x, y - 1);
//   else return 1 / pow(x, -y);
//}