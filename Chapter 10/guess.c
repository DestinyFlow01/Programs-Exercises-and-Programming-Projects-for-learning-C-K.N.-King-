#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Range of number : 
#define MAX_NUMBER 100
#define DEBUG

//Secret number : 
int secret_number;

//Functions : 
void initialize_generator(void);
void obtain_secret(void);
void make_guess(void);

int main() {
	printf("Guess the secret number between 1 and %d\n\n", MAX_NUMBER);

	char command;
	//Secret number : 
	initialize_generator();

	do{
		obtain_secret();
		printf("A new number has been chosen.\n");
		#ifdef DEBUG
			printf("Secret number = %d\n", secret_number);
		#endif
		make_guess();
		printf("Play again? (Y/N) "); scanf(" %c", &command); 
		printf("\n");
	}while(command == 'y' || command == 'Y');
}

void initialize_generator(void) {srand( (unsigned) time(NULL));}
void obtain_secret(void) {secret_number = rand()%MAX_NUMBER + 1;}
void make_guess(void) {
	int guess, num_guess = 0; 

	for(;;) {
		num_guess++;
		printf("Enter guess : "); scanf("%d", &guess);
		if(guess == secret_number) {
			printf("You won in %d guesses!\n\n", num_guess);
			return;
		}
		else if (guess < secret_number) printf("Too low; try again.\n");
		else printf("Too high; try again.\n");
	}
}