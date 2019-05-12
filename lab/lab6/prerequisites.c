/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex1
 * prerequisites.c
 * This program read a list of modules and check the 
 * prerquisites for the target module.
 * Pham Quang Minh
 * C06
 */

#include <stdio.h>
#include <string.h>
#define MAX_MOD  10
#define MAX_LEN  7

int scanModules(char [][MAX_LEN]);
int computePrereq(char [][MAX_LEN], int, char [], char [][MAX_LEN]);
void printPrereq(char [][MAX_LEN], int, char []);

int main(void) {
	int numModules, numPrereq;
	char 	codes[MAX_MOD][MAX_LEN],			// the list of modules codes
			target[MAX_LEN],					// the target module
			prerequisites[MAX_MOD][MAX_LEN];	// prerequisites of the target module

	numModules = scanModules(codes);

	printf("Choose a module: ");
	scanf("%s", target);

	numPrereq = computePrereq(codes, numModules, target, prerequisites);

	printPrereq(prerequisites, numPrereq, target);

	return 0;
}

// Print the prerequisites
// pre-con: module codes have length = MAX_LEN - 1
void printPrereq(char prerequisites[][MAX_LEN], int numPrereq, char target[]) {
	int i;

	if (numPrereq == -1) {
		printf("No such module %s\n", target);
	}
	else if (numPrereq == 0) {
		printf("No prerequisites for %s\n", target);
	}
	else {
		printf("Prerequisites for %s:", target);
		for (i = 0; i < numPrereq; i++){
			printf(" %s", prerequisites[i]);
		}
		printf("\n");
	}
}

// Scan the modules list
// pre-con: module codes have length = MAX_LEN - 1
int scanModules(char codes[][MAX_LEN]) {
	int numModules;
	int i;
	
	printf("Enter number of modules: ");
	scanf("%d", &numModules);
	printf("Enter %d modules:\n", numModules);
	for (i=0; i<numModules; i++)
		scanf("%s", codes[i]);
	return numModules;
}

// Compute the number of prerequisites and write the
// prerequisite codes to the prerequisites[] array
// pre-con: module codes have length = MAX_LEN - 1, numModules >= 2
int computePrereq(char codes[][MAX_LEN], int numModules, char target[], char prerequisites[][MAX_LEN]) {
	int count = 0;
	int i;
	int isInTheList = 0;
	for (i=0; i<numModules; i++) {
		if (   (codes[i][0] == target[0])
			&& (codes[i][1] == target[1])
			&& (codes[i][2] <  target[2])
			&& (codes[i][3] <= target[3])
			&& (codes[i][4] <= target[4])
			&& (codes[i][5] <= target[5])) 
		{
			strcpy(prerequisites[count], codes[i]); 
			count++;
		}
		if (!strcmp(codes[i], target))
			isInTheList = 1;
	}
	if (!isInTheList)
		return -1;
	else
		return count;
}