/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex1
 * invest.c
 * This program calculates the final amount given principal amount,
 * interest rate, and number of years, based on compound interest.
 * Pham Quang Minh
 * C06
 */
#include <stdio.h>
#include <math.h>
int main(void) {
	//variables declaration
	int principal, rate, numYears;
	float amount;

	//variables input
	printf("Enter principal amount: ");
	scanf("%d", &principal);

	printf("Enter interest rate   : ");
	scanf("%d", &rate);

	printf("Enter number of years : ");
	scanf("%d", &numYears);

	//calculations
	amount = principal*(1-pow(rate/100.0,numYears+1))/(1-rate/100.0);

	//output
	printf("Amount = $%.2f\n",amount);

	return 0;
}
