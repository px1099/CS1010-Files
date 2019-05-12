/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex3
 * bisection.c
 * Pham Quang Minh
 * C06
 * This program find the approximated root of a polynominal function
 */

#include <stdio.h>
#include <math.h>
#define THRESHOLD 0.0001

double polynomial(double, int, int, int, int);

int main(void) {
	int    c3, c2, c1, c0; // coefficients of polynomial
	double a, b,           // endpoints
	       pA, pB;         // function values at endpoints
	double m, pM;          // midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);
	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a, &b);
	m = (a+b)/2;
	pA = polynomial(a, c3, c2, c1, c0);
	pM = polynomial(m, c3, c2, c1, c0);
	while((fabs(b-a) >= THRESHOLD) && (pM != 0)) {
		if(pM*pA > 0) {
			a = m;
			pA = pM;
		} else {
			b = m;
			pB = pM;
		}
		m = (a+b)/2;
		pM = polynomial(m, c3, c2, c1, c0);
	}
	printf("root = %.6f\n", m);
	printf("p(root) = %.6f\n", pM);
	return 0;
}

// This function calculate the polynomial function value.
double polynomial(double x, int c3, int c2, int c1, int c0) {
	return c0 + c1*x + c2*pow(x,2) + c3*pow(x,3);
}