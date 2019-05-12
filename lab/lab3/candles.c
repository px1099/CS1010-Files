/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex1
 * candles.c
 * This program find the number of candles can be burned, given the number 
 * of candles and the number of residuals needed to make a new candle.
 * Pham Quang Minh
 * C06
 */

#include <stdio.h>

int count_candles(int ,int );

int main(void) {
	int no_of_candles, residuals_per_candle, candles_burned;
	printf("Enter number of candles and \n");
	printf("number of residuals to make a new candle: ");
	scanf("%d %d", &no_of_candles, &residuals_per_candle);
	candles_burned = count_candles(no_of_candles, residuals_per_candle);
	printf("Total candles burnt = %d\n", candles_burned);
	return 0;
}

// This function calculates numbers of candle burned given the number 
// of candles and the number of residuals needed to make a new candle.
// The number of residuals needed to make a new candle must be larger than 1.
int count_candles(int num_cdl, int rsd_per_cdl) {
	int cdl_brn = 0;
	while (num_cdl >= rsd_per_cdl) {
		cdl_brn += num_cdl - num_cdl % rsd_per_cdl;
		num_cdl = num_cdl / rsd_per_cdl + num_cdl % rsd_per_cdl;
	}
	cdl_brn += num_cdl;
	return cdl_brn;
}