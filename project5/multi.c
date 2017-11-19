#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdint.h>
#define BILLION 1000000000L
#define ROW 4000
#define COL 4000
int list[8] = {1,2,4,8,10,20,30,40};
int A[ROW][COL], B[ROW][COL], C[ROW][COL];
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

long long int return_sum_of_C(){
	long long int sum = 0;
	int read_num, i, j;
	for (i = 0; i < ROW; i++){
		for (j = 0; j < COL; j++){
			sum += C[i][j];
		}
	}
	return sum;
}

// FORMAT : C[i][j] -> lseek(fd,(4000*4*i)+(4*j),SEEK_SET);
// i : column, j : row

void *multi (void * arg){
	struct threadData *myData;
	myData = (struct threadData*) arg;
	int row, cnt;
	row = myData->row;
	cnt = myData->cnt;

	int i, j, k, start_point = row * cnt * 4;
	int sum = 0;

	for (i = row * cnt; i < row * cnt + row; i++){	
		for(j = 0; j < COL; j++){
			sum = 0;
			for(k = 0; k < COL; k++){
				sum += A[i][k] + B[k][j];
			}
			// C[i][j], start_point -> 다음 쓰레드에서 적을 위치
			C[i][j] = sum;
		}
	}
	pthread_exit(NULL);
}

int main(){
	
	long timeDist = 0;
	int count_num = 0, thread_num, thread_cnt, i, j;
	int count_end = sizeof (list) / sizeof (int);
	double result;
	uint64_t diff;
	long long int sum;
	pthread_t threads[40];
	struct timespec tspec, etspec,tt;

	setting_file_A("A.txt");
	setting_file_B("B.txt");
	while (count_num != count_end) {
		clock_gettime(CLOCK_MONOTONIC, &tspec);
		clock_gettime(CLOCK_REALTIME, &tt);
		timeDist = tt.tv_sec;

		thread_num = list[count_num];

		int column = COL;
		int row = ROW / thread_num;
		int rc;

		for (i = 0; i < thread_num; i++){
			threadDataArray[i].row = row;
			threadDataArray[i].cnt = i;
			rc = pthread_create(&threads[i], NULL, multi, (void*)&threadDataArray[i]);			

			if (rc != 0)
				printf("Creating thread error\n");
		}
		for (j = 0; j < thread_num; j++){
			pthread_join(threads[j], NULL);
		}

		sum = return_sum_of_C();

		clock_gettime(CLOCK_MONOTONIC,&etspec);
		clock_gettime(CLOCK_REALTIME, &tt);
		diff = BILLION * (etspec.tv_sec - tspec.tv_sec) + (etspec.tv_nsec - tspec.tv_nsec);
		printf("%d Threads, SUM : %lld, time : %llu\n", thread_num,sum, (long long unsigned int)diff);
		timeDist = tt.tv_sec - timeDist;
		printf("%d Threads, SUM : %lld, time : %ld\n",thread_num,sum,timeDist);
		count_num++;
	}

	return 0;
}

