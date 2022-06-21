#include<stdio.h>
#include<stdlib.h>
#include "Node.h"

void createList(void);

int main()
{
	createList();
}

void displayList(struct node* start) {

	printf("\n Node List: \n");
	struct node* previous;
	struct node* current;
	if (start != NULL) {
		previous = start;
		current = start->next;
		start = start->next;
		previous->next = NULL;
		while (start != NULL) {
			start = start->next;
			current->next = previous;
			previous = current;
			current = start;
		}
		start = previous;
		while (previous != NULL) {
			printf(" %d", previous->value);
			previous = previous->next;
		}
	}
}

void reverseList(struct node* start) {

	struct node* current = start;
	printf("\n Reverse Order: \n");
	while (current != NULL) {
		printf(" %d", current->value);
		current = current->next;
	}
}

void print_max_min(struct node* start) {
	struct node* current = start;
	int max = current->value;
	int min = current->value;
	if (current->next)
		current = current->next;
	while (current) {
		if (current->value > max)
			max = current->value;
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	printf("\n Max is: %d \n", max);
	printf("\n Min is: %d \n", min);
}

void print_sum_avg_count(struct node* start) {

	struct node* current = start;
	int sum = 0;
	int count = 0;
	double avg;

	while (current != NULL) {
		sum += current->value;
		count++;
		current = current->next;
	}
	avg = sum / count;
	printf("\n Sum is : %d \n", sum);
	printf("\n Node Count is : %d \n", count);
	printf("\n Average is : %d \n", avg);
}



void createList() {

	struct node* start = NULL;
	struct node* tmp = NULL;
	int userInput = 0;
	while (userInput >= 0) {
		printf("Input number: (type -1 to finish) ");
		scanf_s("%d", &userInput);
		if (userInput < 0) break;
		tmp = (struct node*)malloc(sizeof(struct node));
		tmp->value = userInput;
		tmp->next = start;
		start = tmp;
	}

	reverseList(start);
	displayList(start);
	print_max_min(start);
	print_sum_avg_count(start);
	free(tmp);
}

