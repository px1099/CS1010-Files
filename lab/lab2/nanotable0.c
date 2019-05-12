/**
 * CS1010 AY2017/18 Sem 1 Lab 2
 * nanotable0.c
 * This program is a nano version of bigtable
 * Pham Quang Minh
 * C06
 */

#include <stdio.h>
#include <string.h>

#define COMMAND_HELP 0
#define COMMAND_EXIT 1
#define COMMAND_SUM 2
#define COMMAND_AVE 3
#define COMMAND_INVALID 4

/* Function prototypes */
int parse_command();

int check_command(char* input);

void print_help();

int simple_sum();

int simple_average();


int main() {
	// Print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	parse_command();

	return 0;
}

// This function work as a command parser in a REPL style
int parse_command() {
	char tmp_command[100] = "";
	int command_code;
	do {
		printf("Waiting for command...\n");
		scanf("%s", tmp_command);

		command_code = check_command(tmp_command);    

		if (command_code == COMMAND_HELP) {
			print_help();
		} else if (command_code == COMMAND_EXIT) {
			printf("See you!\n");
		} else if (command_code == COMMAND_SUM) {
			simple_sum();
		} else if (command_code == COMMAND_AVE) {
			simple_average();
		} else { 
			// others
			printf("No such command: %s, please input command again!\n", tmp_command);
		}
	} while(command_code != COMMAND_EXIT);	
	return 0;
}

// This function receives the number of integers and the value of those integers
// as input and calculates the sum of those integers.
int simple_sum() {
	int sum = 0,
		no_of_integers,
		count,
		number;
	printf("Please indicate the number of integers:\n");
	scanf("%d", &no_of_integers);
	for(count = 1; count <= no_of_integers; ++count){
		printf("Please input the %d",count);
		switch (count % 100) {
			case 11:
			case 12:
			case 13: printf("th "); break;
			default: 
					 switch (count % 10) {
						 case 1: printf("st "); break;
						 case 2: printf("nd "); break;
						 case 3: printf("rd "); break;
						 default: printf("th "); break;
					 }
					 break;
		}
		printf("number:\n");
		scanf("%d", &number);
		sum += number;
	}	
	printf("sum is %d\n", sum);
	return 0;
}

// This function receives the number of integers and the value of those integers
// as input and calculates the average of those integers.
// The result is rounded to the closest integer.
int simple_average() {
	int sum = 0,
		no_of_integers,
		count,
		number,
		rounded_ave;
	double true_ave;
	printf("Please indicate the number of integers:\n");
	scanf("%d", &no_of_integers);
	for(count = 1; count <= no_of_integers; ++count){
		printf("Please input the %d",count);
		switch (count % 100) {
			case 11:
			case 12:
			case 13: printf("th "); break;
			default: 
					 switch (count % 10) {
						 case 1: printf("st "); break;
						 case 2: printf("nd "); break;
						 case 3: printf("rd "); break;
						 default: printf("th "); break;
					 }
					 break;
		}
		printf("number:\n");
		scanf("%d", &number);
		sum += number;
	}
	true_ave = (double)sum/no_of_integers;
	rounded_ave = sum/no_of_integers;
	rounded_ave += (true_ave - rounded_ave >= 0.5);
	printf("average is %d\n", rounded_ave);
	return 0;
}

// This function takes a command as input and returns an integer as output.
/* INPUT    OUTPUT
   help     0
   EXIT     1
   SUM      2
   AVE      3
   others   4
 */
int check_command(char* input) {
	if (strcmp(input,"help") == 0) {
		return COMMAND_HELP;
	}
	else if (strcmp(input,"exit") == 0) {
		return COMMAND_EXIT;
	}
	else if (strcmp(input,"sum") == 0) {
		return COMMAND_SUM;      
	}
	else if (strcmp(input,"ave") == 0) {
		return COMMAND_AVE;
	}
	else {
		return COMMAND_INVALID;
	}
}

// This function prints the help information
void print_help() {
	printf("Commands available: sum, ave, help, exit\n");
}

