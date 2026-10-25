#include<stdio.h>

int main(void) {
	printf("*** ACME checkbook-balancing program ***\n");
	printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\nEnter command : ");

	float balance = 0, credit = 0, debit = 0; 
	int command; scanf("%d", &command);

	for(;;) {
		switch(command) {
			case 0 : balance = 0; break;
			case 1 : printf("Enter amount of credit : "); scanf("%f", &credit); balance += credit; break;
			case 2 : printf("Enter amount of debit : "); scanf("%f", &debit); balance -= debit; break;
			case 3 : printf("Current balance : $%.2f\n", balance); break;
			case 4 : goto done;
			default : printf("Commands: 0=clear, 1=credit, 2=debit, ");
					  printf("3=balance, 4=exit\n\n");
					  break;
		}
		printf("Enter command : "); scanf("%d", &command);
	}
	done : ;
}