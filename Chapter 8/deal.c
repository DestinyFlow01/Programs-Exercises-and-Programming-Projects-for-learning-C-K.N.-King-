#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4

int main(void) {
	bool val_in_hand[NUM_RANKS][NUM_SUITS] = {false};
	const char suit[] = {'c', 's', 'd', 'h'};
	const char rank[] = {'a', '2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k'};

	srand((unsigned) time(NULL));
	int num_card;
	printf("Enter number of cards in hand : ");
	scanf("%d", &num_card);

	printf("Your hand : ");
	int card_idx = 0, suit_idx, rank_idx;
	while(card_idx < num_card) {
		suit_idx = rand() % 4;
		rank_idx = rand() % 13;
		if(val_in_hand[rank_idx][suit_idx]) continue;
		val_in_hand[rank_idx][suit_idx] = true;
		printf("%c%c ", suit[suit_idx], rank[rank_idx]);
		card_idx++;
	}
	printf("\n");
}