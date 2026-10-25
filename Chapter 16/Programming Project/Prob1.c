#include<stdio.h>
#define NAME_LEN 30

struct dialing_code {
	char* country;
	int code;
};

const struct dialing_code country_code[] = {
	{"Argentina", 54}, {"Bangladesh", 880},
	{"Brazil", 55}, {"Burma (Myanmar)", 95},
	{"China", 86}, {"Colombia", 57},
	{"Congo, Dem. Rep. of", 243}, {"Egypt", 20},
	{"Ethiopia", 251}, {"France", 33},
	{"Germany", 49}, {"India", 91},
	{"Indonesia", 62}, {"Iran", 98},
	{"Italy", 39}, {"Japan", 81},
	{"Mexico", 52}, {"Nigeria", 234},
	{"Pakistan", 92}, {"Philippines", 63},
	{"Poland", 48}, {"Russia", 7},
	{"South Africa", 27}, {"South Korea", 82},
	{"Spain", 34}, {"Sudan", 249},
	{"Thailand", 66}, {"Turkey", 90},
	{"Ukraine", 380}, {"United Kingdom", 44},
	{"United States", 1}, {"Vietnam", 84}
};

void Find_Code(int code) {
	int num_code = sizeof(country_code) / sizeof(country_code[0]);

	int idx = -1;
	for(int i = 0; i < num_code; i++) {
		if(code == country_code[i].code) {
			idx = i;
			break;
		}
	}

	if(idx == -1) printf("Country code not found\n");
	else printf("Country code %d is for country %s\n", code, country_code[idx].country);
}

int main(void) {
	int code;
	printf("Enter country code : "); scanf(" %d", &code);
	Find_Code(code);
}