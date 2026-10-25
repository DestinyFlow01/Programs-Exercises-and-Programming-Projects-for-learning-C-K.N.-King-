#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

//Macro : 
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

//Mode : 
// #define DEBUG

//Function prototype : 
void read_cards(char[], int[]);
void analyze_hand(char[], int[], bool*, bool*, int*, int*, int*);
void print_result(const bool*, const bool*, const int*, const int*, const int*);
void selection_sort(int[], int);

int main() {
	bool straight, flush; 
	int num_pair, num_3pair, num_4pair;
	char suits[NUM_CARDS];
	int ranks[NUM_CARDS];

	for(;;) {
		read_cards(suits, ranks);
		analyze_hand(suits, ranks, &straight, &flush, &num_pair, &num_3pair, &num_4pair);
		print_result(&straight, &flush, &num_pair, &num_3pair, &num_4pair);
	}
}

void read_cards(char suits[], int ranks[]) {
	int num_accepted = 0; 
	char rank, suit; 
	bool invalid, duplicated;

	for(;;) {
		invalid = duplicated = false; 
		ranks[num_accepted] = suits[num_accepted] = '\0';

		printf("Enter a card : "); rank = tolower(getchar());
		if(rank == '0') exit(EXIT_SUCCESS);
		suit = tolower(getchar());
		while(getchar() != '\n');

		//Check for bad card : 
		switch(rank) {
			case '2' : ranks[num_accepted] = 2; break;
			case '3' : ranks[num_accepted] = 3; break;
			case '4' : ranks[num_accepted] = 4; break;
			case '5' : ranks[num_accepted] = 5; break;
			case '6' : ranks[num_accepted] = 6; break;
			case '7' : ranks[num_accepted] = 7; break;
			case '8' : ranks[num_accepted] = 8; break;
			case '9' : ranks[num_accepted] = 9; break;
			case 't' : ranks[num_accepted] = 10; break;
			case 'j' : ranks[num_accepted] = 11; break;
			case 'q' : ranks[num_accepted] = 12; break;
			case 'k' : ranks[num_accepted] = 13; break;
			case 'a' : ranks[num_accepted] = 14; break;
			default : invalid = true;
		}

		switch(suit) {
			case 'c' : case 'd' : case 'h' : case 's' : 
			suits[num_accepted] = suit; break;
			default : invalid = true;
		}
		if(invalid) {
			printf("Bad card; ignored\n"); continue;
		} 

		//Check for duplication : 
		for(int i = 0; i<num_accepted; i++) {
			bool suit_eq = suits[num_accepted] == suits[i];
			bool rank_eq = ranks[num_accepted] == ranks[i];
			if(rank_eq && suit_eq) duplicated = true;
		}
		if(duplicated) {
			printf("Duplicate card; ignored\n"); continue;
		} 

		num_accepted++;
		if(num_accepted == NUM_CARDS) return;
	}
}

void analyze_hand(char suits[], int ranks[], bool* straight, bool* flush, int* num_pair, int* num_3pair, int* num_4pair) {
	//Before analyzing, set the external variables to default : 
	*straight = *flush = false; 
	*num_pair = *num_3pair = *num_4pair = 0;

	//Analyzing hand :
	//Test for flush : 
	char suit = suits[0]; 
	*flush = true; //Assume flush is true : 
	for(int i = 1; i<NUM_CARDS; i++) {
		if(suit != suits[i]) {
			*flush = false; break;
		}
	}

	//Test for straight : 
	int arr[NUM_CARDS] = {};
	for(int i = 0; i<NUM_CARDS; i++) arr[i] = ranks[i];
	selection_sort(arr, NUM_CARDS);
	if(arr[NUM_CARDS-1] - arr[0] != 4) *straight = false;
	else {
		*straight = true; //Assume straight = true
		bool found = true;
		for(int i = 1; i<NUM_CARDS; i++) {
			if(arr[i] - arr[i-1] != 1) {
				found = false; break;
			}
		}
		if(found) {
			*straight = true; return;
		}
		else *straight = false;
	}

	//Pairs, 3 and 4 of a kind
	int diff[NUM_CARDS] = {[0] = -1};
	for(int i = 1; i<NUM_CARDS; i++) diff[i] = arr[i] - arr[i-1]; 
	
	int num_eq = 0; //Tracking the 0 in difference 
	for(int i = 1; i<NUM_CARDS; i++) {
		if(diff[i] == 0) num_eq++;
		if(diff[i] != 0 || i == NUM_CARDS-1) {
			if(num_eq == 1) (*num_pair)++;
			else if (num_eq == 2) (*num_3pair)++;
			else if (num_eq == 3) (*num_4pair)++;

			num_eq = 0;
		}
		

		#ifdef DEBUG
			printf("diff = %d, num pair = %d, num 3 pair = %d, num 4 pair = %d\n", diff[i], num_pair, num_3pair, num_4pair);
		#endif
	}
	
}

void print_result(const bool* straight, const bool* flush, const int* num_pair, const int* num_3pair, const int* num_4pair) {
	if(*straight && *flush) printf("Straight flush");
	else if (*num_4pair == 1) printf("Four-of-a-kind");
	else if (*num_3pair == 1 && *num_pair == 1) printf("Full house");
	else if (*flush) printf("Flush");
	else if (*straight) printf("Straight");
	else if (*num_3pair == 1) printf("Three-of-a-kind");
	else if (*num_pair == 2) printf("Two pairs");
	else if (*num_pair == 1) printf("Pair");
	else printf("High card");
	printf("\n\n");
}

void selection_sort(int a[], int n) {
	if(n == 1) return;

	int max = a[0], max_index = 0;
	for(int i = 1; i<=n-1; i++) {
		max_index = (max < a[i]) ? i : max_index;
		max = (max < a[i]) ? a[i] : max;
	} 
	
	int temp = a[n-1];
	a[n-1] = max;
	a[max_index] = temp;

	selection_sort(a, n-1);
}