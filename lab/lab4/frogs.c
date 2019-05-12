/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex3
 * frogs.c
 * This program is a game of moving the frogs to cross the bridge
 * Pham Quang Minh
 * C06
 */

#include <stdio.h>

int jump(int, int[]);
void printBridge(int, int[]);
int checkGameState(int, int, int[]);

int main(void) {

	int bridge[1000];
	int i;
	int lengthOfBridge;
	int empty_space;

	int numMoves = 0;
	int gameState;

	printf("Please enter the length of the bridge: ");
	scanf("%d", &lengthOfBridge);

 	for (i=0; i<lengthOfBridge; i++) {
		int frogType;
		printf("Please insert frogs at position %d: ", i);
		scanf("%d", &frogType);
		bridge[i] = frogType;
		if (bridge[i] == 0) {
			empty_space = i;
		}
	}

	printf("Input completed\n");
	printBridge(lengthOfBridge, bridge);
	gameState = checkGameState(empty_space, lengthOfBridge, bridge);
	printf("Please start moving the frogs\n");
	while (gameState == 0) {
		empty_space = jump(empty_space, bridge);
		printBridge(lengthOfBridge, bridge);
		numMoves++;
		gameState = checkGameState(empty_space, lengthOfBridge, bridge);
	}
	if (gameState == -1) {
		printf("Oh no! It seems like the two clans of frogs are stuck!\n");
	} else { 
		printf("Congratulations! The frogs took %d jump%c to cross the bridge!\n", 
		numMoves, (numMoves>1)?'s':' ');
	}
	return 0;
}

//This function is provided for you
/**
 * Prints out the current state on the bridge
 * @param size (int) represents the size of bridge
 * @param bridge[] contains the current state of the bridge
 **/
void printBridge(int size, int bridge[]) {

	int i;
	printf("Position: ");
	for (i=0; i<size; i++) {
		printf("%2d ", i);
	}
	printf("\n");

	printf("Bridge:   ");
	for (i=0; i<size; i++) {
		printf("%2d ", bridge[i]);
	}
	printf("\n");
}

// This function asks the user for a move and implements it if it is valid.
int jump(int empty_space, int bridge[]) {
	int position;
	printf("Move the frog at position: ");
	scanf("%d", &position);
	while (!((1<=bridge[position]*(empty_space-position)) 
	&& (bridge[position]*(empty_space-position)<=2))) {
		printf("Invalid move!\n");
		printf("Move the frog at position: ");
		scanf("%d", &position);
	}
	bridge[empty_space] = bridge[position];
	bridge[position] = 0;
	return position;
}

// This function checks the state of the game.
int checkGameState(int empty_space, int lengthOfBridge, int bridge[]) {
	int i;
	if (((empty_space-2>=0) && (bridge[empty_space-2]==1))
	|| ((empty_space-1>=0) && (bridge[empty_space-1]==1))
	|| ((empty_space+1<lengthOfBridge) && (bridge[empty_space+1]==-1))
	|| ((empty_space+2<lengthOfBridge) && (bridge[empty_space+2]==-1))) {
		return 0;						//The game can be continued
	}
	for (i=0; i<lengthOfBridge-1; i++) {
		if (bridge[i]>bridge[i+1]) {
			return -1;					//Game over!
		}
	}
	return 1;							//Victory!
}