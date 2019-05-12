/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex3
 * Game of Life
 * Pham Quang Minh
 * C06
 */

#include <stdio.h>

#define DIM_ROW 20
#define DIM_COL 20
#define DEAD    '-'
#define LIFE    'O'
#define MAX_GEN 5

int genesis(char[][DIM_COL+2]); 
void display(int, char[][DIM_COL+2]);
void copy_board(char[][DIM_COL+2], char[][DIM_COL+2]);
void next_generation(char[][DIM_COL+2], int[]);
int check_life(char[][DIM_COL+2], char[][DIM_COL+2], int, int);
int check_dead(char[][DIM_COL+2], char[][DIM_COL+2], int, int);

int main(void) {
	char 	board[DIM_ROW+2][DIM_COL+2]; 	// the community
	int		lives = 0,						// how many lives in community
			generation = 0,
			changes[2];	// number of {life_to_dead, dead_to_life} cells in the latest generation

	lives = genesis(board);
	do {
		next_generation(board, changes);
		lives += changes[1]-changes[0];
		generation++;
	} while ((generation<MAX_GEN)&&(lives != 0)&&((changes[0]+changes[1])!=0));
	display(generation, board); 

	return 0;
}

// To initialise the community with generation 0 from user's input, and
// return the number of life cells read.
// Sentinels are used here. Dead cells are padded around the actual
// community area.
int genesis(char community[][DIM_COL+2]) {
	int population = 0;
	int r, c; 

	// Fill left-most and right-most columns with dead cells.
	for (r=0; r < DIM_ROW + 2; r++)
		community[r][0] = community[r][DIM_COL + 1] = DEAD;

	// Fill top and bottom rows with dead cells.
	for (c=1; c < DIM_COL + 1; c++)
		community[0][c] = community[DIM_ROW + 1][c] = DEAD;

	// Fill the middle 20x20 area with input data
	for (r=1; r<=DIM_ROW; r++) {
		for (c=1; c<=DIM_COL; c++) {
			community[r][c] = fgetc(stdin);
			if (community[r][c] == LIFE)
				population++;
		}
		fgetc(stdin);  // to read the newline character
	}

	return population;
}

// To display the community
void display(int generation, char community[][DIM_COL+2]) {
	int r, c;

	printf("Generation %d:\n", generation);
	for (r=1; r <= DIM_ROW; r++) {
		for (c=1; c <= DIM_COL; c++) {
			printf("%c", community[r][c]);
		}
		printf("\n");
	}
}

// To copy the board from the first one to the second one.
void copy_board(char community[][DIM_COL+2], char temp[][DIM_COL+2]) {
	int r,c;
	
	for (r=0; r<DIM_ROW+2; r++)
		for (c=0; c<=DIM_COL+2; c++)
			temp[r][c] = community[r][c];
}

// To generate next generation and write the number of life_to_dead cells
// and the number of dead to life cell into changes[].
void next_generation(char community[][DIM_COL+2], int changes[]) {
	int r,c;
	char temp[DIM_ROW+2][DIM_COL+2];
	
	changes[0] = changes[1] = 0;
	copy_board(community, temp);
	for (r=1; r<=DIM_ROW; r++) {
		for (c=1; c<=DIM_COL; c++) {
			if (community[r][c] == LIFE)
				changes[0] += check_life(community, temp, r, c);
			else
				changes[1] += check_dead(community, temp, r, c);
		}
	}
}

// To check the number of neighbors around the life cell 
// and changes the state of the cell base on it. 
// Return 1 if cell dies, 0 if cell still lives.
int check_life(char community[][DIM_COL+2], char temp[][DIM_COL+2], int row, int col) {
	int i,j, count = -1;
	
	for (i=-1; i<=1; i++) {
		for (j=-1; j<=1; j++) {
			if (temp[row+i][col+j] == LIFE)
				count++;
		}
	}
	if ((count==2)||(count==3))
		return 0;
	else {
		community[row][col] = DEAD;
		return 1;
	}
}

// To check the number of neighbors around the dead cell 
// and changes the state of the cell base on it. 
// Return 1 if cell become alive, 0 if cell still dead.
int check_dead(char community[][DIM_COL+2], char temp[][DIM_COL+2], int row, int col) {
	int i,j, count = 0;
	
	for (i=-1; i<=1; i++) {
		for (j=-1; j<=1; j++) {
			if (temp[row+i][col+j] == LIFE)
				count++;
		}
	}
	if (count==3) {
		community[row][col] = LIFE;
		return 1;
	} else
		return 0;
}

