/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex3
 * packing.c
 * This program finds the maximum number of slabs can be fit into 
 * a tray in 2 certain orientations
 * Pham Quang Minh
 * C06
 */

#include <stdio.h>

//function prototype
int compute_max_slabs(int a,int b,int c, int d);

//main program
int main(void) {

	//variables declaration
	int max_slabs, tray_length, tray_width, slab_length, slab_width;

	//variables input
	printf("Enter dimension of tray: ");
	scanf("%d %d",&tray_length,&tray_width);

	printf("Enter dimension of slab: ");
	scanf("%d %d",&slab_length,&slab_width);

	//calculation
	max_slabs = compute_max_slabs(tray_length,tray_width,slab_length,slab_width);

	//output
	printf("Maximum number of slabs = %d\n", max_slabs);

	return 0;
}

//function declaration
int compute_max_slabs(int a,int b,int c,int d) {
	int num_slabs_1 = (a/c)*(b/d);
	int num_slabs_2 = (a/d)*(b/c);
	int result;
	if (num_slabs_1 > num_slabs_2) {
		result = num_slabs_1;
	}
	else {
		result = num_slabs_2;
	}
	return result;
}
