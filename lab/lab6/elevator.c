/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex3
 * elevator.c
 * This program simulates the usage of the elevators and prints the 
 * required outputs: floor, passsenger, usage, most used elevator.
 * Pham Quang Minh
 * C06
 */

#include <stdio.h>
#include <string.h>
#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

typedef struct { 
	int floor;		// the floor the elevator is at
	int passenger;	// number of passenger in the elevator
	int usage;		// total number of usage in the elevator
} elevator_t;

void setupElevators(elevator_t [], int);
void readSequences(char [][MAX_LEN], int);
void runElevators(elevator_t [], char [][MAX_LEN], int);
void goToFloor(elevator_t *, int);
void printElevators(elevator_t [], int size);
int mostUsedElevator(elevator_t [], int);

int main(void){
	int size;
	elevator_t elevators[MAX_ELEVATORS];
	char sequences[MAX_ELEVATORS][MAX_LEN];
	
	printf("Enter number of elevators: ");
	scanf("%d", &size);
	
	setupElevators(elevators, size);
	readSequences(sequences, size);
	
	runElevators(elevators, sequences, size);
	
	printElevators(elevators, size);
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size));
	
	return 0;
}

// Initializing the elevators.
// pre-con: size > 0
void setupElevators(elevator_t elevators[], int size){
	int i;
	for (i=0; i<size; i++) {
		elevators[i].floor = 1;
		elevators[i].passenger = 0;
		elevators[i].usage = 0;
	}
}	

// Read in the sequences of floors the elevators go to.
// pre-con: 0 < floors < 10
void readSequences(char sequences[][MAX_LEN], int size){
	int i;
	
	for (i = 0; i<size; i++){
		printf("Enter sequence for elevator %d: ", i+1);
		scanf("%s", sequences[i]);
	}
}

// Run the elevators according to their sequences.
// pre-con: sequences do not contain the same value in adjacent position
void runElevators(elevator_t elevators[], char sequences[][MAX_LEN], int size){
	int i, j;
	for (i=0; i<size; i++) 
		for (j=0; sequences[i][j] != '\0'; j++) 
			goToFloor(&elevators[i], sequences[i][j] - '0');
}

// Run the elevator to a floor
// pre-con: 0 < floor < 10, floor != elevator.floor
void goToFloor(elevator_t *elevator, int floor){
	if (floor > (elevator->floor)) {
		(elevator->passenger) += floor;
		if ((elevator->passenger) > 15)
			(elevator->passenger) = 15;
	} else {
		if ((elevator->passenger) < floor) {
			(elevator->usage) += (elevator->passenger);
			(elevator->passenger) = 0;
		} else {
			(elevator->usage) += floor;
			(elevator->passenger) -= floor;
		}
	}
	(elevator->floor) = floor;
}

// Printing the floor, passenger and usage of every elevator
void printElevators(elevator_t elevators[], int size){
	int i;
	for (i=0; i<size; i++) {
		printf("Elevator %d:\n", i+1); 
		printf("Floor: %d\n", elevators[i].floor);
		printf("Number of passengers: %d\n", elevators[i].passenger);
		printf("Usage: %d\n", elevators[i].usage);
	}
}

// Finding the most used elevator
// pre-con: size > 0
int mostUsedElevator(elevator_t elevators[], int size){
	int mostUsed = 0;
	int i;
	for (i=1; i<size; i++) {
		if ((elevators[i].usage > elevators[mostUsed].usage)
			|| ((elevators[i].usage == elevators[mostUsed].usage)
				&& (elevators[i].passenger > elevators[mostUsed].passenger)))
			mostUsed = i;
	}
	return mostUsed + 1;
}