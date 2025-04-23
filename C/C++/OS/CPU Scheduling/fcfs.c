#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define BUF_SIZE 100

// variable
int time;
FILE* output;
// struct
typedef struct PCB {
	int pid, arrival_time, burst_time;
	double priority;
	int waiting_time;
	int turnaround_time;
	int response_time;
	int isResponded;
	struct PCB *next;
}PCB;
typedef struct Ready_queue {
	struct PCB* pcb;
	struct PCB* tail;
}Ready;
typedef struct Running_queue {
	struct PCB* pcb;
	int prev_pcb;
	int time_q;
}Running;

// functions
PCB* new_pcb(void);
void push(Ready*, PCB**);
int isNull(PCB**);
void fcfs(Ready*, Running*);
void rr(Ready*, Running*, int);
void priority(Ready*, Running*);
void preempt(Ready*, Running*, double);
void next_run(Ready*, Running*);
void update(Ready*, double);

// main function
int main(int argc, char* argv[]) {
	double idle = 0;
	int total_waiting_time = 0;
	int total_turnaround_time = 0;
	int total_response_time = 0;
	int time_q = atoi(argv[3]);
	double alpha = atof(argv[4]);

	//data structure set by reading data from input file
	PCB* job_queue[10]; // define the job queue;
	for (int i = 0; i < 10; i++) {
		job_queue[i] = new_pcb();
	}
	FILE* input = fopen(argv[1], "r");
	if (input == NULL) {
		printf("open error\n");
		exit(0);
	}
	output = fopen(argv[2], "w");
	if (output == NULL) {
		printf("open eroor\n");
		exit(0);
	}
	int column = 0;
	int index = 0;
	while(feof(input) == 0) {
		column = 0;
		char buffer[BUF_SIZE];
		fgets(buffer, BUF_SIZE, input);
		char *token = strtok(buffer, " ");
		while(token != NULL) {
			if(index >= 10) {
				break;
			}
			if(column == 0) {
				job_queue[index]->pid = atoi(token);
			} else if (column == 1) {
				job_queue[index]->priority = atoi(token);
			} else if (column == 2) {
				job_queue[index]->arrival_time = atoi(token);
			} else if (column == 3) {
				job_queue[index]->burst_time = atoi(token);
			}
			
			token = strtok(NULL, " ");
			column++;
		}
		index++;
		
		
	}

	// process scheduling start

	time = 0;
	// Ready_queue create
	Ready ready;
	ready.pcb = NULL;
	ready.tail = NULL;
	// Running_queue create
	Running running;
	running.pcb = NULL;
	running.prev_pcb = 0;
	running.time_q = 0;

	fputs("Scheduling : FCFS\n", output);
	fputs("=============================================\n", output);
	fclose(input);
	fclose(output);
	
	output = fopen(argv[2], "a");
	while(1) {
		// Push the PCB from Job queue -> Ready queue
		for (int i = 0; i < 10; i++) {
			if (job_queue[i] == NULL)	
				continue;
			if (job_queue[i]->arrival_time == time) {
				push(&ready, &job_queue[i]);
			}
		}
		// Terminate process
		if (running.pcb != NULL) {
			if ((running.pcb)->burst_time == 0) {
				running.prev_pcb = 1;
				fprintf(output, "<time %d> process %d is finished\n", time, (running.pcb)->pid);
				(running.pcb)->turnaround_time = time - (running.pcb)->arrival_time;
				total_turnaround_time += (running.pcb)->turnaround_time;
				total_response_time += (running.pcb)->response_time;
				total_waiting_time += (running.pcb)->waiting_time;
				free(running.pcb);
				running.pcb = NULL;
				if (isNull(job_queue) && ready.pcb == NULL) {
					fprintf(output, "<time %d> all process finish\n", time);
					break;
				}
			}
		}

		// Scheduling
		fcfs(&ready, &running);
		
		// queue state update and print current state
		if (running.pcb != NULL) { 
	 		(running.pcb)->burst_time--;
			running.time_q--;
			fprintf(output, "<time %d> process %d is running\n", time, (running.pcb)->pid);
		} else {
			idle++;
			running.prev_pcb = 0;
			fprintf(output, "<time %d> ---- system is idle ----\n", time);
		}
		update(&ready, alpha);
		
		
		time++;
	}
	fputs("============================================\n", output);
	// Print Performance
	fprintf(output, "Average cpu usage : %.2f %%\n", ((time-idle)/(double)time)*100);
	fprintf(output, "Average waiting time : %.1f\n", total_waiting_time/10.0);
	fprintf(output, "Average response time : %.1f\n", total_response_time/10.0);
	fprintf(output, "Average turnaround time : %.1f\n", total_turnaround_time/10.0);
	fclose(output);
	return 0;
}


// Create PCB
PCB* new_pcb() {
	PCB* temp = (PCB*)malloc(sizeof(PCB));
	temp->waiting_time = 0;
	temp->turnaround_time = 0;
	temp->response_time = 0;
	temp->isResponded = 0;
	temp->next = NULL;
	
	return temp;
}
// Change new state to ready state
void push(Ready *ready, PCB** pcb) {
	if ((*ready).pcb == NULL) {
		(*ready).pcb = *pcb;
		(*ready).tail = *pcb;
		fprintf(output, "<time %d> [new arrival] process %d\n", time, (*pcb)->pid);
		*pcb = NULL;
		return;
	}
	PCB* temp = ((*ready).pcb);
	
	((*ready).tail)->next = *pcb;
	(*ready).tail = *pcb;
	fprintf(output, "<time %d> [new arrival] process %d\n", time, (*pcb)->pid);
	*pcb = NULL;
}
// Is there process in jop queue?
int isNull(PCB* pcb[]) {
	int result = 0;
	for (int i = 0; i < 10; i++) {
		if (pcb[i] == NULL) {
			result = 1;
		} else {
			result = 0;
			break;
		}
	}
	return result;
}
// Scheduler algorithms

// FCFS
void fcfs(Ready *ready, Running *running) {
	if ((*running).pcb != NULL) {
		return;
	}
	if ((*ready).pcb != NULL) {
		((*running).pcb) = (*ready).pcb;
		(*ready).pcb = ((*ready).pcb)->next;
		if (((*running).pcb)->isResponded == 0) {
			((*running).pcb)->response_time = time-(((*running).pcb)->arrival_time);
			((*running).pcb)->isResponded = 1;
		}
		if ((*running).prev_pcb == 1) {
			fputs("----------------------------- (Context-Switch)\n", output);;
		}
		((*running).pcb)->next = NULL;
	}
	
}
// RR
void rr(Ready *ready, Running *running, int time_q) {
	if ((*running).pcb != NULL) {
		if ((*running).time_q > 0) {
			return;
		}
		if ((*ready).pcb == NULL) {
			(*running).time_q = time_q;
			return;
		}
		PCB* temp = (*running).pcb;
		(*running).pcb = (*ready).pcb;
		
		((*ready).tail)->next = temp;
		(*ready).pcb = ((*ready).pcb)->next;
		(*ready).tail = temp;
	} else {
		if ((*ready).pcb != NULL) {
			((*running).pcb) = (*ready).pcb;
			(*ready).pcb = ((*ready).pcb)->next;
		} else
			return;
	}
	if (((*running).pcb)->isResponded == 0) {
		((*running).pcb)->response_time = time-(((*running).pcb)->arrival_time);
		((*running).pcb)->isResponded = 1;
	}
	if ((*running).prev_pcb == 1) {
		fputs("----------------------------- (Context-Switch)\n", output);;
	}
	((*running).pcb)->next = NULL;
	(*running).time_q = time_q;
	(*running).prev_pcb = 1;
}
// Priority with Aging
void priority(Ready *ready, Running *running) {
	if ((*ready).pcb == NULL)
		return;
	if ((*running).pcb != NULL) {
		preempt(ready, running, ((*running).pcb)->priority);
	} else {
		next_run(ready, running);
	}
	if ((*running).pcb == NULL)
		return;
	if (((*running).pcb)->isResponded == 0) {
		((*running).pcb)->response_time = time-(((*running).pcb)->arrival_time);
		((*running).pcb)->isResponded = 1;
	}
	((*running).pcb)->next = NULL;
	if ((*running).pcb != NULL) {
		(*running).prev_pcb = 1;
	}
}
// functions associated wity priority

// If running pcb is exist
void preempt(Ready *ready, Running *running, double first_priority) {
	if ((*ready).pcb == NULL)
		return;
	PCB *temp = (*ready).pcb;
	PCB *selected = NULL;
	PCB *prev = NULL;
	PCB *next = NULL;
	if (temp->priority > first_priority) {
		selected = temp;
		next = temp->next;
		first_priority = selected->priority;
	}
	while (temp->next != NULL) {
		if (temp->next->priority > first_priority) {
			selected = temp->next;
			prev = temp;
			next = selected->next;
		}
		temp = temp->next;
	}
	// No selection
	if (selected == NULL)
		return;
	// If selected is pcb the ready queue header point to
	temp = (*running).pcb;
	if (prev == NULL) {
		(*running).pcb = selected;
		(*ready).pcb = selected->next;
		if ((*ready).pcb == NULL) {
			(*ready).tail = NULL;
		}
	} else if (next == NULL) { // If selected is pcb queue tail point to
		(*running).pcb = selected;
		prev->next = NULL;
		(*ready).tail = prev;
	} else {
		(*running).pcb = selected;
		prev->next = next;
	}
	if ((*ready).pcb == NULL) {
		(*ready).pcb = temp;
		(*ready).tail = temp;
		(*ready).tail->next = NULL;
	} else {
		(*ready).tail->next = temp;
		(*ready).tail = temp;
		(*ready).tail->next = NULL;
	}
	if ((*running).prev_pcb == 1) {
		fputs("----------------------------- (Context-Switch)\n", output);;
	}
}
// If no running pcb
void next_run(Ready *ready, Running *running) {
	if ((*ready).pcb == NULL)
		return;
	double first_priority = ((*ready).pcb)->priority;
	PCB *selected = (*ready).pcb;
	PCB *prev = NULL;
	PCB *next = selected->next;
	PCB *temp = (*ready).pcb;
	while (temp->next != NULL) {
		if (temp->next->priority > first_priority) {
			selected = temp->next;
			prev = temp;
			next = selected->next;
			first_priority = selected->priority;
			fprintf(output, "%d", selected->pid);
		}
		temp = temp->next;
	}
	// If selected is pcb the ready queue header point to
	if (prev == NULL) {
		(*running).pcb = selected;
		(*ready).pcb = selected->next;
		if ((*ready).pcb == NULL) {
			(*ready).tail = NULL;
		}
	} else if (next == NULL) { // If selected is pcb queue tail point to
		(*running).pcb = selected;
		prev->next = NULL;
		(*ready).tail = prev;
	} else {
		(*running).pcb = selected;
		prev->next = next;
	}
	if ((*running).prev_pcb == 1) {
		fputs("----------------------------- (Context-Switch)\n", output);;
	}
}
	

// Update waiting time of process in ready queue
void update(Ready *ready, double alpha) {
	if ((*ready).pcb == NULL)
		return;
	PCB *temp = (*ready).pcb;
	while (temp != NULL) {
		temp->waiting_time++;
		temp->priority += alpha;
		temp = temp->next;
	}
}
