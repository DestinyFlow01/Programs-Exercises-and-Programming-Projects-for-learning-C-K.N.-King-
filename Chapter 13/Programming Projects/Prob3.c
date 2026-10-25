#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define VAL_MAX 50

int main(void) {
	bool val_in_hand[NUM_RANKS][NUM_SUITS] = {false};
	const char* suit[] = {"clubs", "spades", "diamonds", "hearts"};
	const char* rank[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

	srand((unsigned) time(NULL));
	int num_card;
	printf("Enter number of cards in hand : ");
	scanf("%d", &num_card);

	printf("\nYour hand : \n");
	int card_idx = 0, suit_idx, rank_idx;
	while(card_idx < num_card) {
		suit_idx = rand() % 4;
		rank_idx = rand() % 13;
		if(val_in_hand[rank_idx][suit_idx]) continue;
		val_in_hand[rank_idx][suit_idx] = true;

		char str_val[VAL_MAX];
		strcpy(str_val, rank[rank_idx]);
		strcat(str_val, " of ");
		strcat(str_val, suit[suit_idx]);
		printf("%s\n", str_val);
		card_idx++;
	}
}