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
	int msg_id, len;
	struct msg_st msg;

	msg_id = msgget(123, 0444);

	len = msgrcv(msg_id, &msg, 50, 0, 0);

	fprintf(stderr, "\n\tMsg. received is : %s\n", msg.buf);
	fprintf(stderr, "\tLength of msg. text : %d\n\n", len);

	msgctl(msg_id, IPC_RMID, 0);

	return 0;
}
