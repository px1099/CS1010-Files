/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex1
 * square.c
 * Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.
 * Pham Quang Minh
 * C06
 */

#include <stdio.h>
#define MAXSIZE 9

int scanSquare(int [][MAXSIZE], int []);
int isSemiMagic(int [][MAXSIZE], int [], int);
int sumRow(int [][MAXSIZE], int, int);
int sumCol(int [][MAXSIZE], int, int);

int main(void) { 
	int size;
	int square[MAXSIZE][MAXSIZE];
	int list[MAXSIZE*MAXSIZE] = {0};
	size = scanSquare(square, list);
	if (isSemiMagic(square, list, size)) {
		printf("It is a semi-magic square.\n");  
	} else {
		printf("It is not a semi-magic square.\n");
	}
	return 0;
}

// Read in size of square and values in the square.
// Count the number of each interger (1 to size^2) to the list.
// Return the size of square.
int scanSquare(int square[][MAXSIZE], int list[]) {
	int r, c, size;
	
	printf("Enter size of square: ");
	scanf("%d", &size);
	printf("Enter values in the square: \n");
	for (r=0; r<size; r++) {
		for (c=0; c<size; c++) {
			scanf("%d", &square[r][c]);
			list[square[r][c]-1] += 1;
		}
	}	
	
	return size;
}

// Check if square is a semi-magic square or not.
int isSemiMagic(int square[][MAXSIZE], int list[], int size) {
	int i, r, c;
	int sum = sumRow(square, size, 0);
	
	for (i=0; i<size*size; i++) {
		if (list[i] == 0)
			return 0;
	}
	for (r=1; r<size; r++) {
		if (sum != sumRow(square, size, r))
			return 0;
	}
	for (c=0; c<size; c++) {
		if (sum != sumCol(square, size, c))
			return 0;
	}
	
	return 1;
}

// Calculate sum of the specified row in the square.
int sumRow(int square [][MAXSIZE], int size, int row) {
	int i, sum_r = 0;
	
	for (i=0; i<size; i++)
		sum_r += square[row][i];
	
	return sum_r;
}

// Calculate sum of the specified column in the square.
int sumCol(int square [][MAXSIZE], int size, int col) {
	int i, sum_c = 0;
	
	for (i=0; i<size; i++)
		sum_c += square[i][col];
	
	return sum_c;
}