#include <sys/times.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <memory.h>

#define SIZE 1028
#define SHARED_KEY 8888
#define MSQ1 5555
#define MSQ2 6666
#define MSQ3 7777

int que_id_1, que_id_2, que_id_3;

typedef struct msgq{
	long mtype;
	short from;
	short to;
	char buf[1024];
} MSG;

typedef struct log {
	short pid;
	char buf[1024];
} log;

typedef struct ChatLog{
	int num;
	log chat[10];
} ChatLog;

ChatLog* Chat;
int shmid;
void *shared_pos;
/**
	특정 Chat Queue 에 있는 type 으로 보내는 메세지와 받은 메세지를 구분.
	1 인 경우에 server 에서 읽어서 메세지 보내준다.
	3 인 경우에는 client 쪽에서 받은 메세지로 인식.

	보내는 대상이 0 인 경우에는 Chat Log Memory 에 저장.
	Client 는 메세지를 보내는 시점에 누구에게 보내는지 선택 가능.
 **/
void PRINT(){
	ChatLog *tmp = (ChatLog *)shared_pos;
	printf("num : %d\n", tmp -> num);
	for (int i = 0; i < tmp -> num; ++i) {
		printf("%d %s\n", tmp -> chat[i].pid, tmp -> chat[i].buf);
	}
}

void shm_at_fun() {
	Chat = NULL;
	if ((void *)-1 == (shared_pos = shmat(shmid, (void *)0, 0))){
		printf("shmat failed\n");
		exit(-1);
	}
	Chat = (ChatLog *)shared_pos;
}

void shm_dt_fun() {
	if (shmdt(shared_pos) == -1){
		printf("shmdt failed\n");
		exit(-1);
	}
	shared_pos = (void *)0;
}

void helper(MSG* msg) {	
	msg -> mtype = 3;
	log tmp;
	switch(msg -> to){
		case 1 :
			printf("PID %d send a message to PID %d. Message : %s\n", msg -> from, msg -> to, msg -> buf);
			msgsnd(que_id_1, msg, SIZE, IPC_NOWAIT);
			break;
		case 2 :
			printf("PID %d send a message to PID %d. Message : %s\n", msg -> from, msg -> to, msg -> buf);
			msgsnd(que_id_2, msg, SIZE, IPC_NOWAIT);
			break;
		case 3 :
			printf("PID %d send a message to PID %d. Message : %s\n", msg -> from, msg -> to, msg -> buf);
			msgsnd(que_id_3, msg, SIZE, IPC_NOWAIT);
			break;
		case 0 : // Chat Log.
			printf("PID %d send a message to Chat Log. Message : %s\n", msg -> from, msg -> buf);
			tmp.pid = msg -> from;
			memcpy(tmp.buf, msg -> buf, sizeof(char) * 1024);
			shm_at_fun();
			memcpy(&Chat -> chat[(Chat -> num) % 100], &tmp, sizeof(log));
			Chat -> num = Chat -> num + 1;
			shm_dt_fun();
			break;
	}
}

int main(){

	shared_pos = (void *)0;
	if (-1 == (shmid = shmget((key_t)SHARED_KEY, sizeof(ChatLog), IPC_CREAT | 0666))) {
		printf("Cannot make shared memory\n");
		return -1;
	}
	if ((void *)-1 == (shared_pos = shmat(shmid, (void *)0, 0))){
		printf("shmat failed\n");
		return -1;
	}
	Chat = (ChatLog *)shared_pos;
	Chat -> num = 0;

	if (shmdt(shared_pos) == -1) {
		printf("shmdt failed\n");
		return -1;
	}
	Chat = NULL;
	shared_pos = (void *)0;

	MSG msg;
	memset(&msg, 0x00, sizeof(msg));

	if (-1 == (que_id_1 = msgget(MSQ1, IPC_CREAT | 0666)))
		return -1;
	if (-1 == (que_id_2 = msgget(MSQ2, IPC_CREAT | 0666)))
		return -1;
	if (-1 == (que_id_3 = msgget(MSQ3, IPC_CREAT | 0666)))
		return -1;
	// 서버는 Queue 를 순회하며 확인할 메세지가 있는지 체크한다.

	while(1) {
		if (msgrcv(que_id_1, &msg, SIZE, 1, IPC_NOWAIT) != -1){
			printf("msgrcv from PID1\n");
			helper(&msg);
		}
		if (msgrcv(que_id_2, &msg, SIZE, 1, IPC_NOWAIT) != -1){
			printf("msgrcv from PID2\n");
			helper(&msg);
		}
		if (msgrcv(que_id_3, &msg, SIZE, 1, IPC_NOWAIT) != -1){
			printf("msgrcv from PID3\n");
			helper(&msg);
		}
	}

	return 0;
}
