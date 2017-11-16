#include <signal.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdio.h> 
void sig_fn (int signo) {
	sigset_t set, oset;
	sigfillset(&set);
	if (sigprocmask(SIG_BLOCK, &set, &oset) < 0) {
		printf("PROCMASK ERR\n");
	}
	printf("Ctrl-C is pressed. Try Again\n");
}
int main() {
	struct sigaction sig;

	sig.sa_handler = sig_fn;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	if (sigaction(SIGINT, &sig, NULL) == -1) {
		printf ("SIGINT : 2 ERR");
		return -1;
	}    
	while(1) {
	}
	return 0;
}

