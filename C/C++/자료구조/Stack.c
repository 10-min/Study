#include<stdio.h>
#define MAX_SIZE 10
void push(int);
int stack_full();
int stack_empty();
void run_push();
void run_pop();
int top = -1;
int stack[MAX_SIZE];
int main() {
	int how_pop, how_push;

	while (1) {
		printf("종료하려면 -1을 입력\n");
		printf("how many push?");
		scanf_s("%d", &how_push);
		printf("how many pop?");
		scanf_s("%d", &how_pop);

		if (how_push == -1 || how_pop == -1) {
			exit(0);
		}
		
		run_push(stack, how_push);
		run_pop(how_pop);

	}
	
		

}
void push(int x) {
	top++;
	stack[top] = x;
}
int pop() {
	int output = stack[top];
	top--;
	return output;
}
int stack_full() {
	if (top >= MAX_SIZE-1) {
		return 1;
	}
	else {
		return 0;
	}
}
int stack_empty() {
	if (top < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void run_push(int stack[], int n) {
	
	for (int i = 0; i < n; i++) {
		int value;
		int j = 0;
		printf("값을 입력하시오: ");
		scanf_s("%d", &value);
		if (stack_full()) {
			printf("stack이 꽉 찼습니다.\n");
			break;
		}
		else {
			push(value);
		}
		printf("stack = ");
		do {
			if (j != 0) {
				printf(" ");
			}
			printf("%d", stack[j]);
			j++;
		} while (j <= top);
		printf("\n");
	}
}
void run_pop(int x) {
	for (int i = 0; i < x; i++) {
		int j = 0;
		
		pop();
		printf("stack = ");
		if (!stack_empty()) {
			do {
				if (j != 0) {
					printf(" ");
				}
				printf("%d", stack[j]);
				j++;
			} while (j <= top);
		}
		else {
			printf("\nstack이 비었습니다.\n");
			break;
		}
		printf("\n");
	}
}