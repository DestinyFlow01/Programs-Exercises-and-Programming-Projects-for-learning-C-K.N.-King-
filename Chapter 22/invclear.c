#include<stdio.h>
#include<stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct {
	int numbers; 
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts;
int main(void) {
	//Open a binary file containing part structures
	FILE* fp;
	if((fp = fopen("inventory.dat", "rb+")) == NULL) {
		fprintf(stderr, "inventory.dat can't be opened. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	//Reads the structures into an array
	num_parts = fread(inventory, sizeof(inventory[0]), MAX_PARTS, fp);

	//set on hand member of each structure to 0 : 
	for(int i = 0; i<num_parts; i++) inventory[i].on_hand = 0;

	//Writing the structures back to the file : 
	fseek(fp, 0, SEEK_SET);
	fwrite(inventory, sizeof(inventory[0]), num_parts, fp);
	fclose(fp);
}