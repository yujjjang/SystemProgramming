#include "hybrid_lock.h"
#include <time.h>
#define BILLION 1000000000.0
int hybrid_lock_init(struct hybrid_lock* hbl_t){
	if(pthread_mutex_init(&hbl_t -> m_lock, NULL) != 0) {
		return -1;
	}
	hbl_t -> acc_try = 0;
	hbl_t -> acc_mutex = 0;
	return 0;
}

int hybrid_lock_destroy(struct hybrid_lock* hbl_t){
	if(pthread_mutex_destroy(&hbl_t -> m_lock) != 0) {
		return -1;
	}
	free(hbl_t);
	hbl_t = NULL;
	return 0;
}

int hybrid_lock_lock(struct hybrid_lock* hbl_t) {
	int ch;
	struct timespec st,en;
	clock_gettime(CLOCK_MONOTONIC, &st);
	while(1){
		clock_gettime(CLOCK_MONOTONIC, &en);
		if( (en.tv_sec - st.tv_sec) + (en.tv_nsec - st.tv_nsec) / BILLION >= 1.0000)
			break;
		for(ch = 0; ch<100000; ch++){
			if (pthread_mutex_trylock(&hbl_t -> m_lock) == 0) {
				hbl_t->acc_try++;
				return 0;
			}
		}
	}
	printf("%.6f\n", (en.tv_sec - st.tv_sec) + (en.tv_nsec - st.tv_nsec) / BILLION);
	pthread_mutex_lock(&hbl_t -> m_lock);
	hbl_t->acc_mutex++;
	return 0;
}

int hybrid_lock_unlock(struct hybrid_lock* hbl_t){
	pthread_mutex_unlock(&hbl_t -> m_lock);
	return 0;
}

