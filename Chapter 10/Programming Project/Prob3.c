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

//External variable : 
bool straight, flush, royal;
int num_pair, num_3pair, num_4pair;
char suits[NUM_CARDS];
int ranks[NUM_CARDS];
int hands[NUM_CARDS][2]; //Row for ranks, col for suits 

//Function prototype : 
void read_cards(void);
void analyze_hand(void);
void print_result(void);
void selection_sort(int[], int);

int main() {
	for(;;) {
		read_cards();
		analyze_hand();
		print_result();
	}
}

void read_cards(void) {
	int num_accepted = 0; 
	char rank, suit; 
	bool invalid, duplicated;

	for(;;) {
		invalid = duplicated = false; 
		hands[num_accepted][0] = hands[num_accepted][1] = '\0';

		printf("Enter a card : "); rank = tolower(getchar());
		if(rank == '0') exit(EXIT_SUCCESS);
		suit = tolower(getchar());
		while(getchar() != '\n');

		//Check for bad card : 
		switch(rank) {
			case '2' : hands[num_accepted][0] = 2; break;
			case '3' : hands[num_accepted][0] = 3; break;
			case '4' : hands[num_accepted][0] = 4; break;
			case '5' : hands[num_accepted][0] = 5; break;
			case '6' : hands[num_accepted][0] = 6; break;
			case '7' : hands[num_accepted][0] = 7; break;
			case '8' : hands[num_accepted][0] = 8; break;
			case '9' : hands[num_accepted][0] = 9; break;
			case 't' : hands[num_accepted][0] = 10; break;
			case 'j' : hands[num_accepted][0] = 11; break;
			case 'q' : hands[num_accepted][0] = 12; break;
			case 'k' : hands[num_accepted][0] = 13; break;
			case 'a' : hands[num_accepted][0] = 14; break;
			default : invalid = true;
		}

		switch(suit) {
			case 'c' : case 'd' : case 'h' : case 's' : 
			hands[num_accepted][1] = suit; break;
			default : invalid = true;
		}
		if(invalid) {
			printf("Bad card; ignored\n"); continue;
		} 

		//Check for duplication : 
		for(int i = 0; i<num_accepted; i++) {
			bool suit_eq = hands[num_accepted][1] == hands[i][1];
			bool rank_eq = hands[num_accepted][0] == hands[i][0];
			if(rank_eq && suit_eq) duplicated = true;
		}
		if(duplicated) {
			printf("Duplicate card; ignored\n"); continue;
		} 

		num_accepted++;
		if(num_accepted == NUM_CARDS) return;
	}
}

void analyze_hand(void) {
	//Before analyzing, set the external variables to default : 
	straight = flush = royal = false; 
	num_pair = num_3pair = num_4pair = 0;

	//Analyzing hand :
	//Test for flush : 
	char suit = hands[0][1]; 
	flush = true; //Assume flush is true : 
	for(int i = 1; i<NUM_CARDS; i++) {
		if(suit != hands[i][1]) {
			flush = false; break;
		}
	}

	//Test for straight : 
	int arr[NUM_CARDS] = {};
	for(int i = 0; i<NUM_CARDS; i++) arr[i] = hands[i][0];
	selection_sort(arr, NUM_CARDS);
	if(arr[NUM_CARDS-1] - arr[0] != 4) straight = false;
	else {
		straight = true; //Assume straight = true
		bool found = true;
		for(int i = 1; i<NUM_CARDS; i++) {
			if(arr[i] - arr[i-1] != 1) {
				found = false; break;
			}
		}
		if(found) {
			straight = true; 
			if(arr[0] == 10 && arr[NUM_CARDS-1] == 14) royal = true;
			return;
		}
		else straight = false;
	}

	//Pairs, 3 and 4 of a kind
	int diff[NUM_CARDS] = {[0] = -1};
	for(int i = 1; i<NUM_CARDS; i++) diff[i] = arr[i] - arr[i-1]; 
	
	int num_eq = 0; //Tracking the 0 in difference 
	for(int i = 1; i<NUM_CARDS; i++) {
		if(diff[i] == 0) num_eq++;
		if(diff[i] != 0 || i == NUM_CARDS-1) {
			if(num_eq == 1) num_pair++;
			else if (num_eq == 2) num_3pair++;
			else if (num_eq == 3) num_4pair++;

			num_eq = 0;
		}
		

		#ifdef DEBUG
			printf("diff = %d, num pair = %d, num 3 pair = %d, num 4 pair = %d\n", diff[i], num_pair, num_3pair, num_4pair);
		#endif
	}
	
}

void print_result(void) {
	if(royal && straight && flush) printf("Royal straight flush");
	else if(straight && flush) printf("Straight flush");
	else if (num_4pair == 1) printf("Four-of-a-kind");
	else if (num_3pair == 1 && num_pair == 1) printf("Full house");
	else if (flush) printf("Flush");
	else if (straight) printf("Straight");
	else if (num_3pair == 1) printf("Three-of-a-kind");
	else if (num_pair == 2) printf("Two pairs");
	else if (num_pair == 1) printf("Pair");
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