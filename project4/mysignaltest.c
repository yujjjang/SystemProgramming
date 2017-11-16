#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>

static sigjmp_buf env_alrm;
static volatile sig_atomic_t canjump;
static void sig_alrm(int signo);
static void sig_int(int signo);
unsigned int sleep2(unsigned int seconds);

int main(void) {
	unsigned int unslept;

	if (signal(SIGINT, sig_int) == SIG_ERR){
		fprintf(stderr, "signal(SIGINT) error");
		exit(-1);
	}

	unslept = sleep2(5);

	printf("sleep2 returned: %u\n", unslept);
	return 0;
}

static void sig_alrm(int signo) {	
	if(canjump == 0) return;
	siglongjmp(env_alrm, 1);
}

static void sig_int(int signo) {
	canjump = 0;
	int i,j;
	volatile int k;
	printf("\nsig_int starting\n");

	/*
	 * 아래 for문이 5초 이상 실행되도록 적당히 바꿔주세요.
	 */
	for (i = 0; i<300000; i++)
		for (j = 0; j<6000; j++)
			k += i*j;

	printf("sig_int finished\n");
	canjump = 1;
}

unsigned int sleep2(unsigned int seconds) {
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		return seconds;

	if (sigsetjmp(env_alrm, SIGINT) == 0){
		canjump = 1;
		alarm(seconds);
		pause();
	}
	return alarm(0);
}
