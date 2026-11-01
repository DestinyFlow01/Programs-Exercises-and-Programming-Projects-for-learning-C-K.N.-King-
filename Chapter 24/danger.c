#include<stdio.h>
#include<signal.h>
#include<setjmp.h>

jmp_buf env;
void f(void);
void handler_SIGINT(int);
void handler_SIGFPE(int);

int main(void) {
	puts("Danger..... SIGINT (CTRL + C) can't be used for now.");
	puts("To kill the program, use this approach : ");
	puts("1. pkill -9 <name of this program> : Sending SIGKILL to kill this program, can't be ignored, blocked or pending");
	puts("2. CTRL + Z : suspend\n3. CTRL + D : EOF \n4. CTRL + \\ : Quit/Abort");
	printf("Press Enter if you have understood the risk and mitigation...");
	getchar();

	signal(SIGINT, handler_SIGINT);	//Original handler is not kept, ironic actually
	signal(SIGFPE, handler_SIGFPE); 
	if(setjmp(env) == 0) {
		for(int i = 0;; i++) printf("i = %d\n", i);
	}
	else {
		sigset_t cur;
		sigprocmask(SIG_BLOCK, NULL, &cur);
		printf("SIGINT blocked: %d\n", sigismember(&cur, SIGINT));
		printf("Successfully land on else part\n");
		printf("SIGFPE blocked: %d\n", sigismember(&cur, SIGFPE));
		raise(SIGFPE);
		raise(SIGINT);
		printf("SIGFPE blocked: %d\n", sigismember(&cur, SIGFPE));
	} 
	
}

void f(void) {
	printf("Calling f\n"); fflush(stdout);
	longjmp(env,1);
	printf("Not executed");
}

void handler_SIGINT(int sig) {
	printf("Triggering SIGINT\n"); fflush(stdout);
	raise(SIGFPE); // f();
	printf("Exiting SIGINT\n"); fflush(stdout);
}

void handler_SIGFPE(int sig) {
	printf("Triggering SIGFPE\n"); fflush(stdout);
	raise(SIGINT);
	printf("Exiting SIGFPE\n"); fflush(stdout);
}