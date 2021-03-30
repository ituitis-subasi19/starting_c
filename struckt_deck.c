#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

struct card{
	const char *face;
	const char *suit;
};

typedef struct card Card;

void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[])
{
	for(int i = 0; i < CARDS; i++) {
		(*(wDeck + i)).face = *(wFace + (i % FACES));
		(*(wDeck + i)).suit = *(wSuit + (i / FACES));
	}
}

void shuffle(Card * const wDeck)
{
	int i, j;
	Card temp;
	for(i = 0; i < CARDS; i++) {
		j = rand() % CARDS;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void deal(Card * const wDeck)
{
	for(int i = 0; i < CARDS; i++) {
		printf("%s of %s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? "   " : "\n");
	}
}

int main()
{
	Card deck[CARDS];
	
	const char *face[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	
	srand(time(NULL));
	
	fillDeck(deck, face, suit);
	shuffle(deck);
	deal(deck);
	
	return 0;
}
