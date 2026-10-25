#include<stdio.h>

int main(void) {
	int i = -17, j, k, n = 5;

	i = 1;
	switch (i % 3) {
	case 0: printf("zero");
	case 1: printf("one");
	case 2: printf("two");
	}

	printf("\n");
}