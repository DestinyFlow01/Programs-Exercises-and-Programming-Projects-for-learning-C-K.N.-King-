#include<stdio.h>

int main(void) {
	int GS1, Group, Publisher, Item, CheckDigit;
	printf("Enter ISBN: "); scanf("%d-%d-%d-%d-%d", &GS1, &Group, &Publisher, &Item, &CheckDigit);
	printf("GSI prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n", GS1, Group, Publisher, Item, CheckDigit);
}