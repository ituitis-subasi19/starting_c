#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
	int die1 = (rand() % 6) + 1;
	int die2 = (rand() % 6) + 1;
	int dieTotal = die1 + die2;
	
	printf("The player rolled %d + %d = %d\n", die1, die2, dieTotal);
	return dieTotal;
}

int main() {
	srand(time(NULL));
	int die = rollDice();
	int point;
	enum status {Continue, won, lost};
	enum status gamestatus;
	
	switch (die) {
		case 7:
		case 11:
			gamestatus = won;
			break;
		case 2:
		case 3:
		case 12:
			gamestatus = lost;
			break;
		default:
			gamestatus = Continue;
			point = die;
			printf("Your point is %d\n", point);
			break;	
	}
	
	while (gamestatus == Continue) {
		die = rollDice();
		if (die == 7) {
			gamestatus = lost;
		} else if (die == point) {
			gamestatus = won;
		}
	}
	
	if (gamestatus == won) {
		printf("You won!");
	} else if (gamestatus == lost) {
		printf("You lost!");
	}
	return 0;
}
