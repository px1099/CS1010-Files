/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex1
 * nanotable1.c
 * This program stores student IDs, scores and preforms tasks based on those.
 * Pham Quang Minh
 * C06
 */

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define MAX_COMMAND_LENGTH 100

/* Function prototypes */
void print_help();
int sum(int [][3], int);
int ave(int [][3], int);
void insert_table(int [][3], int);
void ranking(int [][3], int);

int main(void) {
  
	char input[MAX_COMMAND_LENGTH];
	int table[MAX_COMMAND_LENGTH][3];	// 3 cols: ID, score, rank
	int size = 0;
	
	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	while (TRUE) {
		printf("Waiting for command...\n");
		scanf("%s", input);

		if (strcmp(input,"help") == 0) {
			print_help();
		} else if (strcmp(input,"exit") == 0){
			printf("See you!\n");
			break;
		} else if (strcmp(input,"sum") == 0) {
			if (size == 0) {
				printf("The table is empty\n");
			} else {
				printf("The sum of score is %d\n", sum(table, size));
			}
		} else if (strcmp(input,"ave") == 0) {
			if (size == 0) {
				printf("The table is empty\n");
			} else {
				printf("The average of score is %d\n", ave(table, size));
			}
		} else if (strcmp(input,"insert") == 0) {
			insert_table(table, size);
			size++;
		} else if (strcmp(input,"init") == 0) {
			printf("Initializing table...\n");
			size = 0;
		} else if (strcmp(input,"rank") == 0) {
			if (size == 0) {
				printf("The table is empty\n");
			} else {
				ranking(table, size);
			}
		} else {
			printf("No such command: %s, please input command again!\n", input);
		}
	}
	return 0;
}

// This function prints the help information
void print_help() {
  printf("Commands available: insert, init, sum, ave, rank, help, exit\n");
}

// This function calculates the sum of scores
// pre-con: size>0
int sum(int arr[][3], int size) {
	int i, sum = 0;
	for (i=0; i<size; i++) {
		sum += arr[i][1];
	}
	return sum;
}

// This function calculates the ave of scores (rounded to the nearest integer)
// pre-con: size>0
int ave(int arr[][3], int size) {
	int score_sum = sum(arr, size),
		score_ave = score_sum / size;
	score_ave += (score_sum - (score_ave + 0.5) * size >= 0);
	return score_ave;
}

// This function insert a student's ID and score and re-calculates the students ranking
// pre-con: size >=0
void insert_table(int arr[][3], int size) {
	int i;
	printf("Please input the student's ID...\n");
	scanf("%d", &arr[size][0]);
	printf("Please input the student's score...\n");
	scanf("%d", &arr[size][1]);
	arr[size][2] = 1;
	for (i=0; i<size; i++) {
		if ((arr[size][1]>arr[i][1]) || ((arr[size][1]==arr[i][1]) && (arr[size][0]>arr[i][0]))) {
			arr[size][2]++;
		} else {
			arr[i][2]++;
		}
	}
}

// This function finds the student's ID and score of a given rank
// pre-con: the input rank is a positive integer
void ranking(int arr[][3], int size) {
	int i, rank;
	printf("Please input the rank (1 - %d)...\n", size);
	scanf("%d", &rank);
	while (rank > size) {
		printf("Invalid rank: %d\n", rank);
		printf("Please input the rank (1 - %d)...\n", size);
		scanf("%d", &rank);
	}
	for (i=0; i<size; i++) {
		if (arr[i][2] == rank) {
			printf("ID: %d, Score: %d\n", arr[i][0], arr[i][1]);
			break;
		}
	}
}