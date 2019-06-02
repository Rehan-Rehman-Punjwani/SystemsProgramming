#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int pfd1[2], pfd2[2];

	char sendbuf[BUFSIZ];
	char rcvbuf[BUFSIZ];

	memset(sendbuf, 0, BUFSIZ);
	memset(rcvbuf, 0, BUFSIZ);

	pid_t pid;

	pipe(pfd1);
	pipe(pfd2);

	pid=fork();

	switch(pid){
	case -1:
		perror("fork");
		exit(1);
	case 0:
		close(pfd1[0]);
		fprintf(stderr, "\n\t*** Child Talking ***\n"
				"\tEnter ur message...\n"
				">>> ");

		fgets(sendbuf, BUFSIZ, stdin);
		write(pfd1[1], sendbuf, strlen(sendbuf));
		close(pfd1[1]);

		close(pfd2[1]);
		read(pfd2[0], rcvbuf, BUFSIZ);
		fprintf(stderr, "C-Recvd<<< %s\n", rcvbuf);
		close(pfd2[0]);

		break;
	default:
		close(pfd1[1]);
		read(pfd1[0], rcvbuf, BUFSIZ);
		fprintf(stderr, "P-Recvd<<< %s\n", rcvbuf);
		close(pfd1[0]);

		fprintf(stderr, "\n\t*** Parent Talking ***\n"
				"\tEnter ur message...\n"
				">>> ");
		close(pfd2[0]);
		fgets(sendbuf, BUFSIZ, stdin);
		write(pfd2[1], sendbuf, strlen(sendbuf));
		close(pfd2[1]);

		wait(NULL);
	}

	return 0;
}
