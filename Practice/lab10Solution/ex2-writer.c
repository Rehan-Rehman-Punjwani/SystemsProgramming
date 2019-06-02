#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_st{
	long int flag;
	char buf[50];

};


int main()
{
	int msg_id;
	struct msg_st msg;
	msg.flag = 1;
	memset(msg.buf, 0, 50);

	msg_id = msgget(123, 0666|IPC_CREAT);

	strcpy(msg.buf, "The King is dead, Long Live the King...");

	msgsnd(msg_id, &msg, 50, 0);

	return 0;
}
