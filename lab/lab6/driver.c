/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex2
 * driver.c
 * This program calculate the possible routes given an array of gas stations available within distance.
 * Pham Quang Minh
 * C06
 */

#include <stdio.h>
#define MAX_STATIONS 20
#define INITIAL_FUEL 100

void readStations(int [], int [], int *, int *);
void printStations(int [], int [], int, int);
int calcPossibleRoutes(int [], int[], int, int);
int travel(int [], int [], int, int, int);

int main() {
	int distances[MAX_STATIONS];
	int fuels[MAX_STATIONS];
	int totalDist, numStation;
	int possibleRoute;

	readStations(distances, fuels, &totalDist, &numStation); 
	printStations(distances, fuels, totalDist, numStation); 

	possibleRoute = calcPossibleRoutes(distances, fuels, totalDist, numStation);
	printf("Possible number of routes = %d\n", possibleRoute);

	return 0;
}

// Read the gas stations' distances and available fuel 
// and return the total distance and number of gas stations read.
// Note: Do not change this function
void readStations(int distances[], int fuels[], int *totalDistPtr, int *numStationPtr) {
	int i;

	printf("Enter total distance: ");
	scanf("%d", totalDistPtr);

	printf("Enter number of gas stations: ");
	scanf("%d", numStationPtr);

	printf("Enter distance and amount of fuel for each gas station:\n");
	// gasStation Array will store in such way [dist0, fuel0, dist1, fuel1, dist2, fuel2, ...]
	for (i = 0; i < *numStationPtr; i++) {
		scanf("%d %d", &distances[i], &fuels[i]);
	}
}

// Print total distance and gas stations' distances and fuel
// Note: Do not change this function
void printStations(int distances[], int fuels[], int totalDist, int numStation) {
	int i;

	printf("Total distance = %d\n", totalDist);
	printf("Number of gas stations = %d\n", numStation);
	printf("Gas stations' distances: ");
	for (i = 0; i < numStation; i++) {
		printf("%4d ", distances[i]);
	}
	printf("\n");
	printf("Gas stations' fuel amt : ");
	for (i = 0; i < numStation; i++) {
		printf("%4d ", fuels[i]);
	}
	printf("\n");
}

// Including the starting point and ending point in new arrays
// storing distances and fuels and starting the recursion function
// to calculate total possible number of way to travel.
// In the new array: 0 is the starting point, 1 to numStation 
// are the stations and numStation+1 is the finishing point
int calcPossibleRoutes(int distances[], int fuels[], int totalDist, int numStation) {
	int i;
	int distArray[MAX_STATIONS+2],
		fuelArray[MAX_STATIONS+2];
	
	distArray[0] = 0;
	fuelArray[0] = INITIAL_FUEL;
	distArray[numStation+1] = totalDist;
	fuelArray[numStation+1] = 0;
	for (i=1; i<=numStation; i++) {
		distArray[i] = distances[i-1];
		fuelArray[i] = fuels[i-1];
	}
	return travel(distArray, fuelArray, 0, numStation, INITIAL_FUEL);
}

// Recursive function to calculate number of possible way
// from the "start" point to the finish line with a given fuel
// pre-con: 0 <= start <= numStation+1 
int travel(int distArray[], int fuelArray[], int start, int numStation, int fuel) {
	int numWay = 0;
	int possibleRoute;
	int fuelLeft;
	int i;
	
	if (start == numStation+1)
		return 1;
	else {
		for (i = start+1; i <= numStation+1; i++) {
			possibleRoute = (distArray[i] - distArray[start] <= fuel);
			if (possibleRoute) {
				fuelLeft = fuel - (distArray[i] - distArray[start]) + fuelArray[i];
				numWay += travel(distArray, fuelArray, i, numStation, fuelLeft);
			}
		}
		return numWay;
	}
}