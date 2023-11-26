/*
	program : Infix To Prefix
	name : Tae Min
	Last_edit : 2023-07-14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen �Լ��� ����ϱ� ���� �������
#define MAX_SIZE 100

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;

int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20,19,12,12,13,13,13,0 };

char stack[MAX_SIZE];
char expr[MAX_SIZE]; 
int top = 0;

int eval();
char pop(); 
void push(char item); 
void stackFull();
void stackEmpty();
void prefix(); // �������� ���������� �ٲ��ִ� �Լ�
char printToken(precedence item); 
precedence getToken(char* symbol, int* n); 

void main() {
	int result;
	printf("input data( !! first data must be a ' ' !! ) : ");
	scanf_s("%[^\n]s", expr, sizeof(expr)); 
	prefix(); 
	printf("%s\n", expr);
	result = eval(); 
	printf("%4d\n", result);
}

void push(char item) {
	if (top == MAX_SIZE)
		stackFull();
	stack[++top] = item; 
}

char pop() {
	if (top == -1)
		stackEmpty();
	return stack[top--]; 
}

void stackFull() {
	fprintf(stderr, "Stack is Full");
	exit(1);
}

void stackEmpty() {
	fprintf(stderr, "Stack is Empty");
	exit(1);
}

void prefix() { // ���������� �ٲ��ִ� �Լ��̱� ������ �ڿ��� ���� �ϳ��� ���ʷ� ����.
	char symbol;
	precedence token;
	int n = strlen(expr) - 1; // �ڿ������� ���� ���� n�� ���ڿ��� ���� -1 ��ŭ ���ش�.
	int _top = 0;
	int i = n;
	stack[0] = eos;
	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
		if (token == operand) {
			expr[i--] = symbol;
		}
		else if (token == rparen) { 
			while (stack[top] != lparen) { 
				expr[i--] = printToken(pop()); 
			}
			expr[i--] = printToken(pop());
		}
		else {
			while (isp[stack[top]] > icp[token]) {
				expr[i--] = printToken(pop());
			}
			push(token);
		}
	}
	while ((token = pop()) != eos) {
		expr[i--] = printToken(token);
	}
}

char printToken(precedence item) {
	switch (item) {
	case plus: return '+';
	case minus: return '-';
	case times: return '*';
	case divide: return '/';
	case mod: return '%';
	case lparen: return '(';
	case rparen: return ')';
	}
}

precedence getToken(char* symbol, int* n) {
	*symbol = expr[(*n)--]; 
	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus; 
	case '*': return times;
	case '/': return divide;
	case '%': return mod;
	case ' ': return eos;
	default: return operand;
	}
}

int eval() { // �������� ����ϴ� �Լ�
	precedence token;
	char symbol;
	int op1, op2;
	int n = strlen(expr) - 1; // �������� �ڿ������� ����ϱ� ������ n�� ���ڿ��� ���� -1 ��ŭ���� �Ѵ�.
	token = getToken(&symbol, &n); 
	while (token != eos) { 
		if (token == operand)
			push(symbol - '0'); 
		else {
			op1 = pop(); 
			op2 = pop();
			switch (token) {
			case plus:
				push(op1 + op2);
				break;
			case minus:
				push(op1 - op2);
				break;
			case times:
				push(op1 * op2);
				break;
			case divide:
				push(op1 / op2);
				break;
			case mod:
				push(op1 % op2);
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop(); 
}