#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>
struct hybrid_lock {
	pthread_mutex_t m_lock;
	int acc_try;
	int acc_mutex;
} hybrid_lock;

int hybrid_lock_init(struct hybrid_lock* hbl_t);
int hybrid_lock_destroy(struct hybrid_lock* hbl_t);
int hybrid_lock_lock(struct hybrid_lock* hbl_t);
int hybrid_lock_unlock(struct hybrid_lock* hbl_t);
