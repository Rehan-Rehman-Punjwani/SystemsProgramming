#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>


int main()
{
	int fd1, fd2;
	pid_t pid;
	char sendbuf[BUFSIZ];
	char rcvbuf[BUFSIZ];

	memset(sendbuf, 0, BUFSIZ);
	memset(rcvbuf, 0, BUFSIZ);

	mkfifo("fifo1", 0777);
	mkfifo("fifo2", 0777);

	pid=fork();

	switch(pid){
	case -1:
		perror("fork");
		exit(1);	
	case 0:
		fd1 = open("fifo1", O_WRONLY);

		fprintf(stderr, "\n\t*** Child Talking ***\n"
				"\tEnter ur message...\n"
				">>> ");
		
		fgets(sendbuf, BUFSIZ, stdin);
		write(fd1, sendbuf, strlen(sendbuf));
		close(fd1);

		fd2 = open("fifo2", O_RDONLY);
		read(fd2, rcvbuf, BUFSIZ);
		fprintf(stderr, "C-Recvd<<< %s\n", rcvbuf);
		close(fd2);
	
		break;
	default:
		fd1 = open("fifo1", O_RDONLY);

		read(fd1, rcvbuf, BUFSIZ);
		fprintf(stderr, "P-Recvd<<< %s\n", rcvbuf);
		close(fd1);

		fprintf(stderr, "\n\t*** Parent Talking ***\n"
				"\tEnter ur message...\n"
				">>> ");
	
		fd2 = open("fifo2", O_WRONLY);
		fgets(sendbuf, BUFSIZ, stdin);
		write(fd2, sendbuf, strlen(sendbuf));
		close(fd2);

		wait(NULL);
		unlink("fifo1");
		unlink("fifo2");
	}
	
	return 0;
}
