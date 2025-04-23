#include<stdio.h>
#define MAX_SIZE 10
int front = -1, rear = -1;
void enqueue(int value);
int dequeue();
int queue_full();
int queue_empty();
void run_enqueue(int queue[], int n);
void run_dequeue(int queue[], int n);
int queue[MAX_SIZE];
int main() {
	int how_queue, how_dequeue, option;

	while (1) {
		printf("Select the option:\n");
		printf("1. enqueue\n2. dequeue\n3. exit\n");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			printf("how many enqueue?: ");
			scanf_s("%d", &how_queue);
			run_enqueue(queue, how_queue);
			break;

		case 2:
			printf("how many dequeue?: ");
			scanf_s("%d", &how_dequeue);
			run_dequeue(queue, how_dequeue);
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("다시 입력하십시오.\n");
		}
	}
}
void enqueue(int value) {
	if (front < 0) {
		front = 0;
	}
	rear++;
	queue[rear] = value;
}
int dequeue() {
	int output = queue[front];
	front++;
	return output;
}
int queue_full() {
	if (rear >= MAX_SIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}
int queue_empty() {
	if (front > rear) {
		return 1;
	}
	else {
		return 0;
	}
}
void run_enqueue(int queue[], int n) {
	if (queue_full()) {
		printf("queue가 꽉 찼습니다.\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		int value;
		printf("값을 입력하시오: ");
		scanf_s("%d", &value);
		if (queue_full()) {
			printf("queue가 꽉 찼습니다.\n");
			break;
		}
		else {
			enqueue(value);
		}
	}
	int j = front;
	printf("queue = ");
	do {
		if (j > front) {
			printf(" ");
		}
		printf("%d", queue[j]);
		j++;
	} while (j <= rear);
	printf("\n");
}
void run_dequeue(int queue[], int n) {
	if (queue_empty()) {
		printf("queue가 비었습니다.\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (queue_empty()) {
			break;
		}
		else {
			dequeue();
		}
	}
	printf("queue = ");

	if (queue_empty()) {
		printf("\n");
		return;
	}
	else
	{
		int j = front;
		do {
			if (j > front) {
				printf(" ");
			}
			printf("%d", queue[j]);
			j++;
		} while (j <= rear);
		printf("\n");
	}


}