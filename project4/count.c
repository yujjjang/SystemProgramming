#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>
int fd;
int max_val;

void setting_file(char* pathname){
	int check = 0, read_num;
	if ((fd=open(pathname,O_RDWR,0666)) > 0){
		pread(fd,&read_num,sizeof(int), SEEK_SET);
		if (read_num == check)
			return;
		else {
			pwrite(fd,&check,sizeof(int),SEEK_SET);
			return ;
		}
	}
	else if ((fd = open(pathname, O_RDWR | O_CREAT,0666)) > 0)
	{
		pwrite(fd,&check,sizeof(int),SEEK_SET);
		return ;
	}
}
void all(){
	alarm(1);
}
int valid(){
	int read_num;
	pread(fd,&read_num,sizeof(int),SEEK_SET);
	if(read_num >= max_val){
		return 0;
	}
	return 1;
}
void signal_handler(int signo){
	int read_num;
	pread(fd,&read_num,sizeof(int),SEEK_SET);
	if(read_num == max_val){
		alarm(1);
		return;
	}
	read_num++;
	pwrite(fd,&read_num,sizeof(int),SEEK_SET);
	alarm(1);
}	

int main(int argc, char * argv[]){
	clock_t before;
	before = clock();
	if (argc < 2) return -1;
	int read_num;
	max_val = atoi(argv[1]);

	pid_t child, first_process = getpid();

	if(max_val <= 0){
		printf(" ERROR 1 : first argument <= 0\n");
		return -1;
	}
	if(argc < 3) {
		printf("You have to put filename\n");
		return -1;
	}

	setting_file(argv[2]);
	(void)signal(SIGUSR1, signal_handler);
	(void)signal(SIGALRM, all);
	double result;
	if ((child = fork()) < 0){
		printf("ERROR 2 : fork error\n");
	}
	else if (child == 0){
		if ( ( child = fork()) < 0){
			printf("ERROR 3 : fork error\n");
		}
		else if (child == 0){ // third Process
			pause();
			while (valid()){
				kill(first_process, SIGUSR1);
				if(valid()) pause();
				else break;
			}
			kill(first_process, SIGUSR1);
			exit(1);
		}else{
			//second Process
			pause();
			while(valid()){
				kill(child, SIGUSR1);
				if(valid()) pause();
				else break;
			}
			kill(child, SIGUSR1);
			exit(1);
		}
	}
	else { // first Process
		sleep(1);
		while(valid()){
			kill(child, SIGUSR1);
			if(valid()) pause();
			else break;
		}
		kill(child, SIGUSR1);
	}
	result = (double)(clock() - before) / CLOCKS_PER_SEC;
	pread(fd, &read_num, sizeof(int),SEEK_SET);
	printf("Max value : %d, Real value read from file  : %d\n", max_val ,read_num);
	printf("Time : %8.3f\n", result);
	return 0;
}
