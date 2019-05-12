/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex2
 * square_free.c
 * Pham Quang Minh
 * C06
 * This program compares 2 range to see which one has more square-free 
 * integers and how many square-free integers that one has.
 */

#include <stdio.h>
#include <math.h>

int sqr_free(int,int);

int main(void) {
	int lower1, upper1, lower2, upper2,	// The lower and upper bound of 2 ranges.
		num1, num2;	// The number of square-free integers in each of those ranges.
	// Please input in the following sequence: lower1,upper1,lower2,upper2.
	printf("Enter four positive integers: ");
	scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);
	num1 = sqr_free(lower1, upper1);
	num2 = sqr_free(lower2, upper2);
	if (num1 > num2) 
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower1, upper1, num1);
	else if (num1 < num2) 
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower2, upper2, num2);
	else 
		printf("Both ranges have the same number of square-free numbers: %d\n", num1);
	return 0;
}

// This function calculate the number of square-free integers in a range.
int sqr_free(int lower, int upper) {
	int count = 0,
		is_sqr_free,
		number,	// The number which is being checked to be square-free or not.
		i;	// Run in loops to check if the checking number is square-free or not.
	for(number = lower; number <= upper; ++number) {
		is_sqr_free = 1;
		for(i=2; i <= sqrt(number); ++i) {
			if (number % (i*i) == 0) {
				is_sqr_free = 0;
				break;
			}
		}
		count += is_sqr_free;
	}
	return count;
}