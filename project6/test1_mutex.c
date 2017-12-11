#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>
#define BILLION 1000000000.0
long g_count = 0;
pthread_mutex_t g_mutex;
void *thread_func(void *arg)
{
	long i, count = (long)arg;

	/*
	 * Increase the global variable, g_count.
	 * This code should be protected by
	 * some locks, e.g. spin lock, and the lock that 
	 * you implemented for assignment,
	 * because g_count is shared by other threads.
	 */
	for (i = 0; i<count; i++) {
		/************ Critical Section ************/
		pthread_mutex_lock(&g_mutex);
		g_count++;
		pthread_mutex_unlock(&g_mutex);
		/******************************************/
	}
}

int main(int argc, char *argv[])
{
	pthread_t *tid;
	if (pthread_mutex_init(&g_mutex, NULL) != 0) {
		return -1;
	}
	long i, thread_count, value;
	int rc;

	/*
	 * Check that the program has three arguments
	 * If the number of arguments is not 3, terminate the process.
	 */
	if (3 != argc) {
		fprintf(stderr, "usage: %s <thread count> <value>\n", argv[0]);
		exit(0);
	}

	/*
	 * Get the values of the each arguments as a long type.
	 * It is better that use long type instead of int type,
	 * because sizeof(long) is same with sizeof(void*).
	 * It will be better when we pass argument to thread
	 * that will be created by this thread.
	 */
	thread_count = atol(argv[1]);
	value = atol(argv[2]);

	/*
	 * Create array to get tids of each threads that will
	 * be created by this thread.
	 */
	tid = (pthread_t*)malloc(sizeof(pthread_t)*thread_count);
	if (!tid) {
		fprintf(stderr, "malloc() error\n");
		exit(0);
	}

	/*
	 * Create a threads by the thread_count value received as
	 * an argument. Each threads will increase g_count for
	 * value times.
	 */
	struct timespec stspec, enspec;
	clock_gettime(CLOCK_MONOTONIC, &stspec);
	for (i = 0; i<thread_count; i++) {
		rc = pthread_create(&tid[i], NULL, thread_func, (void*)value);
		if (rc) {
			fprintf(stderr, "pthread_create() error\n");
			free(tid);
			pthread_mutex_destroy(&g_mutex);
			exit(0);
		}
	}

	/*
	 * Wait until all the threads you created above are finished.
	 */
	for (i = 0; i<thread_count; i++) {
		rc = pthread_join(tid[i], NULL);
		if (rc) {
			fprintf(stderr, "pthread_join() error\n");
			free(tid);
			pthread_mutex_destroy(&g_mutex);
			exit(0);
		}
	}
	clock_gettime(CLOCK_MONOTONIC, &enspec);

	/*
	 * Print the value of g_count.
	 * It must be (thread_count * value)
	 */
	float diff = (enspec.tv_sec - stspec.tv_sec) + (enspec.tv_nsec - stspec.tv_nsec) / BILLION;
	printf("%ld Threads, Count value : %ld, Total time : %.6f\n", thread_count, value, diff);
	printf("value: %ld\n", g_count);

	free(tid);
	return 0;
}