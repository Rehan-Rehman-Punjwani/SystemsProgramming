#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	pid = fork();

	switch(pid){
	case -1:
		perror("fork");
		exit(1);
	case 0:
		exit(0);
	default:
		sleep(1);
		execlp("ps", "ps", "-l", (char *)NULL);
	}
}
