/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex2
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * Pham Quang Minh
 * C6
 */

#include <stdio.h>
#define DIM 12

void scanBoard(int [][DIM]);
int search(int [][DIM], int, int []);
int findHorizontal(int [][DIM], int, int);
int findVertical(int [][DIM], int, int);
int findDiagonal(int [][DIM], int, int);

int main(void) {
	int board[DIM][DIM] = { {0} };
	int search_digit;
	int maxLength;		// length of the longest sequence of search digit
	int position[2];	// array storing starting position of the longest sequence {row, col}

	scanBoard(board);
	scanf("%d", &search_digit);
	maxLength = search(board, search_digit, position);
	if (maxLength > 0) {
		printf("Length of longest sequence = %d\n", maxLength); 
		printf("Start at (%d,%d)\n", position[0], position[1]);      
	}
	else
		printf("No such sequence.\n");
	return 0;
}

// Read data into the board.
void scanBoard(int arr[][DIM]) {
	int i,j;
	for (i=0; i<DIM; i++) 
		for (j=0; j<DIM; j++) 
			scanf("%d ", &arr[i][j]);
}


// Find the longest sequence base on the search digit.
// Write its starting position in to position[].
// Return the length of the longest sequence.
int search(int arr[][DIM], int key, int position[]) {
	int	length = 0,
		h_length, v_length, d_length,
		i, j;
	for (i=0; i<DIM; i++) {
		for (j=0; j<DIM; j++) {
			if (arr[i][j] == key) {
				h_length = findHorizontal(arr, i, j);
				v_length = findVertical(arr, i, j);
				d_length = findDiagonal(arr, i, j);
				if (h_length > length) {
					length = h_length;
					position[0] = i;
					position[1] = j;
				}
				if (v_length > length) {
					length = v_length;
					position[0] = i;
					position[1] = j;
				}
				if (d_length > length) {
					length = d_length;
					position[0] = i;
					position[1] = j;
				}
			}
		}
	}
	return length;
}

// Find the length of the horizontal sequence of a given position.
int findHorizontal(int arr[][DIM], int r, int c) {
	int i, h_length = 1;
	for (i=0; (c+i+1<DIM) && (arr[r][c+i] == arr[r][c+i+1]); i++)
		h_length++;
	return h_length;
}

// Find the length of the vertical sequence of a given position.
int findVertical(int arr[][DIM], int r, int c) {
	int i, v_length = 1;
	for (i=0; (r+i+1<DIM) && (arr[r+i][c] == arr[r+i+1][c]); i++)
		v_length++;
	return v_length;
}

// Find the length of the diagonal sequence of a given position.
int findDiagonal(int arr[][DIM], int r, int c) {
	int i, d_length = 1;
	for (i=0; (r+i+1<DIM) && (c+i+1<DIM) && (arr[r+i][c+i] == arr[r+i+1][c+i+1]); i++)
		d_length++;
	return d_length;
}