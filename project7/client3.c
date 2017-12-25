#include <sys/times.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <memory.h>

#define SIZE 1028
#define MSG3 7777
#define SHARED_KEY 8888
int que_id;

typedef struct log {
  short pid;
  char buf[1024];
} log;

typedef struct ChatLog{
  int num;
  log chat[100];
} ChatLog;

typedef struct msgq{
  long mtype;
  short from;
  short to;
  char buf[1024];
} MSG;

MSG msg;

void helper_send(){
  memset(&msg, 0x00, sizeof(MSG));
  int num;
  char buf[1024];
  memset(buf, 0x00, sizeof(char) * 1024);
  printf("Send a message to :  [0 is a server's pid]\n");
  scanf("%d", &num);
	getchar();
  printf("Message : ");
	fgets(buf, 1024, stdin);
	buf[strlen(buf) - 1] = '\0';

  msg.mtype = 1;
  msg.from = 3;
  msg.to = num;
  memcpy(msg.buf, buf, sizeof(char) * 1024);

  msgsnd(que_id, &msg, SIZE, IPC_NOWAIT);
}

void helper_check(){
  memset(&msg, 0x00, sizeof(MSG));

  if(msgrcv(que_id, &msg, SIZE, 3, IPC_NOWAIT) != -1) {
    printf("[ %d ] : %s\n", msg.from, msg.buf);
  }
}

void helper_check_log(){
  int shm_id;
  void *shared_pos = (void *)0;
  ChatLog Chat;

  while(-1 == (shm_id = shmget((key_t)SHARED_KEY, sizeof(ChatLog), IPC_CREAT | 0606))){};

  if ((void *)-1 == (shared_pos = shmat(shm_id, (void *)0, 0))){
    printf("shmat fail\n");
    return;
  }
  memcpy(&Chat, shared_pos, sizeof(ChatLog));

  int num = (Chat.num >= 100) ? 100 : Chat.num;
  for(int i = 0; i < num; ++i) {
    printf(" [ %d ] : %s\n", Chat.chat[i].pid, Chat.chat[i].buf);
  }
  shmdt(shared_pos);
}


int main(){

  if (-1 == (que_id = msgget((key_t)MSG3, IPC_CREAT | 0666))) {
    return -1;
  }

  int cmd;
  while(1) {
    printf("(1) Send a message (2) Check a message (3) Check a chat log (4) exit\n");
    scanf("%d", &cmd);

    switch(cmd){
      case 1:
        helper_send();
        break;
      case 2:
        helper_check();
        break;
      case 3:
        helper_check_log();
        break;
      case 4:
        exit(0);
				break;
			default :
				printf("Please Check a command\n");
				break;
    }
  }
  return 0;
}

