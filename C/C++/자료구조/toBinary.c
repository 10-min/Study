#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_NODE 31


// Stack struct
typedef struct stack {
	int data;
	struct stack* next;
} stack;

// global variables
stack* top = NULL;
numOfNode = 0;

// define of function
stack* new_Node(int key);
int is_full();
int is_empty();
void push(int key);
int pop();
void toBinary(int decimal);
void print_result(int sign);



int main() {
	char decimal[20];
	
	while(1) {
	printf("Enter the positive integer decimal: (exit: #)\n");
	scanf_s("%s", decimal, sizeof(decimal));
	if (strcmp(decimal, "#") == 0) {
		break;
	}
	toBinary(atoi(decimal));
	getchar(decimal);
	}
	return 0;
}

// Create new Node
stack* new_Node(int key) {
	
	if (is_full()) {
		return NULL;
	}

	numOfNode++;

	stack* temp;
	temp = (stack*)malloc(sizeof(stack));
	temp->data = key;
	temp->next = top;
	return temp;
}

//Is stack full?
int is_full() {
	if (numOfNode >= MAX_NODE) {
		printf("stack is full!!");
		return 1;
	}
	else {
		return 0;
	}
}

// Is stack empty?
int is_empty() {
	if (numOfNode <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}

// push in stack a data
void push(int key) {
	top = new_Node(key);
}

// pop from stack
int pop() {
	if (is_empty()) {
		return NULL;
	}
	int* temp;

	numOfNode--;
	int output = top->data;
	temp = top;
	top = top->next;
	free(temp);
	return output;
}

void toBinary(int decimal) {
	int sign;
	if (decimal >= 0) {
		sign = 1;
		while (decimal != 0) {
			push(decimal % 2);
			decimal = decimal / 2;
		}
		print_result(sign);
	}
	else {
		sign = -1;
		int up = 1;
		decimal = -decimal;
		while (decimal != 0) {
			if (up + !(decimal % 2) > 1) {
				push(decimal % 2);
				decimal = decimal / 2;
			}
			else {
				push(!(decimal % 2) + up);
				decimal = decimal / 2;
				up = 0;
			}
		}
		print_result(sign);
	}
	
}

void print_result(int sign) {
	if (sign == 1) {
		while (!is_empty()) {
			printf("%d ", pop());
		}
		printf("\n");
	}
	else {
		printf("2ÀÇ º¸¼ö: ");
		printf("%d ", 1);
		while (!is_empty()) {
			printf("%d ", pop());
		}
		printf("\n");
	}
}