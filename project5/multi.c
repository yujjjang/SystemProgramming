#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdint.h>
#include <memory.h>
#define BILLION 1000000000L
#define ROW 4000
#define COL 4000
int list[8] = {1,2,4,8,10,20,30,40};
int A[ROW][COL], B[ROW][COL];
// 쓰레드 함수에 2개의 인자를 넘기기 위해서
struct threadData{
	int row;
	int cnt;
}; 
// 최대 40개의 쓰레드 인자를 담을 수 있는 구조체 배열
struct threadData threadDataArray[40];

void setting_file_A(char* pathname) {
	FILE* fp;
	int val = 1;
	int k;
	if ((fp = fopen(pathname,"r")) != NULL) {
		fseek(fp, 0, SEEK_SET);
		for (int i = 0; i < ROW; ++i) {
			for (int j = 0; j < COL; ++j) {
				fscanf(fp, "%d",&k);
				A[i][j] = k;
			}
		}
	} else {
		fp = fopen(pathname, "w");
		for (int i = 0; i < ROW; ++i) {
			for (int j = 0; j < COL; ++j) {
				fprintf(fp, "%d\t", val);
				A[i][j] = val;
			}
			fprintf(fp, "\n");
		}
	}
	fclose(fp);
}

void setting_file_B(char* pathname) {
	FILE* fp;
	int val = 1;
	int k;
	if ((fp = fopen(pathname,"r")) != NULL) {
		fseek(fp, 0, SEEK_SET);
		for (int i = 0; i < ROW; ++i) {
			for (int j = 0; j < COL; ++j) {
				fscanf(fp, "%d",&k);
				B[i][j] = k;
			}
		}
	} else {
		fp = fopen(pathname, "w");
		for (int i = 0; i < ROW; ++i) {
			for (int j = 0; j < COL; ++j) {
				fprintf(fp, "%d\t", val);
				B[i][j] = val;
			}
			fprintf(fp, "\n");
		}
	}
	fclose(fp);
}
// i : column, j : row

void *multi (void * arg){
	struct threadData *myData;
	myData = (struct threadData*) arg;
	int i, j, k;
	long long int sum = 0;
	for (i = myData -> row * myData -> cnt; i < myData -> row * myData -> cnt + myData -> row; i++){	
		for(k = 0; k < COL; k++){
			for(j = 0; j < COL; j++){
				sum += A[i][j] * B[j][k];
			}
		}
	}
	pthread_exit((void*)sum);
}

int main(){
	
	long timeDist = 0;
	int count_num = 0, thread_num, thread_cnt;
	int i, j;
	int count_end = sizeof (list) / sizeof (int);
	double result;
	uint64_t diff;
	pthread_t threads[40];
	struct timespec tspec, etspec,tt;
	setting_file_A("A.txt");
	setting_file_B("B.txt");
	
	long long int SUM[40];
	count_num = 5;
	while (count_num != count_end) {
		memset(SUM, 0x00, sizeof(long long int) * 40);
		long long int sum = 0;
		thread_num = list[count_num];
		int column = COL;
		int row = ROW / thread_num;
		int rc;
		
		clock_gettime(CLOCK_MONOTONIC, &tspec);
		clock_gettime(CLOCK_REALTIME, &tt);
		timeDist = tt.tv_sec;

		for (i = 0; i < thread_num; i++){
			threadDataArray[i].row = row;
			threadDataArray[i].cnt = i;
			rc = pthread_create(&threads[i], NULL, multi, (void*)&threadDataArray[i]);			

			if (rc != 0)
				printf("Creating thread error\n");
		}

		for (j = 0; j < thread_num; j++){
			pthread_join(threads[j],(void*)&SUM[j]);
		}
		if (thread_num == 30) {
			for(int i = 3990; i < ROW; ++i) {
				for(int k = 0; k < COL; ++k) {
					for (int j = 0; j < COL; ++j){
						sum += A[i][k] * B[k][j];
					}
				}
			}
		}
		for (j = 0; j < thread_num; ++j) {
			sum += SUM[j];
		}
		clock_gettime(CLOCK_MONOTONIC,&etspec);
		clock_gettime(CLOCK_REALTIME, &tt);
		diff = BILLION * (etspec.tv_sec - tspec.tv_sec) + (etspec.tv_nsec - tspec.tv_nsec);
		printf("%d Threads, SUM : %lld, time : %llu\n", thread_num, sum, (long long unsigned int)diff);
		timeDist = tt.tv_sec - timeDist;
		printf("%d Threads, SUM : %lld, time : %ld\n",thread_num, sum, timeDist);
		count_num++;
	}
	return 0;
}

