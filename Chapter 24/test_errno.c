#include<stdio.h>
#include<math.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

// #define DOMAIN_ERROR
// #define RANGE_ERROR


int main(void) {
	double y; 
	double x = -1; 
	double exp_power = 3000; 

	#if defined DOMAIN_ERROR
		y = sqrt(x);

		if(errno != 0) {
			printf("From strerror : %s\n", strerror(errno));
			perror("From perror : Sqrt error");
			exit(EXIT_FAILURE);
		}
	#elif defined RANGE_ERROR
		y = exp(exp_power);

		if(errno != 0) {
			printf("From strerr : %s\n", strerror(errno));
			perror("From perror : Overflowing");
			exit(EXIT_FAILURE);
		}
	#else
		perror("Test");

		for(int i = 0; i<1000; i++) {
			char* res = strstr(strerror(i), "Unknown");
			if(res == NULL) printf("i = %d, error msg = %s\n", i, strerror(i));
		}
		
	#endif
}
