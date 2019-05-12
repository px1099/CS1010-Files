/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex2
 * box.c
 * This program calculate the surface area and the diagonal length of a box
 * Pham Quang Minh
 * C06
 */

#include <stdio.h>
#include <math.h>

//function prototype
int compute_surface_area(int a,int b,int c);
double compute_diagonal(int a,int b,int c);

//main program
int main(void) {

	//variables defination
	int length, width, height, area;
	double diagonal;

	//variables input
	printf("Enter length: ");
	scanf("%d",&length);

	printf("Enter width : ");
	scanf("%d",&width);

	printf("Enter height: ");
	scanf("%d",&height);

	//calculations
	area = compute_surface_area(length,width,height);
	diagonal = compute_diagonal(length,width,height);

	//output
	printf("Surface area = %d\n",area);
	printf("Diagonal = %.2lf\n",diagonal);
	return 0;
}

//function declaration
int compute_surface_area(int a,int b,int c) {
	int result = 2*(a*b+b*c+a*c);
	return result ;
}
double compute_diagonal(int a,int b,int c) {
	double result = sqrt(a*a+b*b+c*c);
	return result ;
}
