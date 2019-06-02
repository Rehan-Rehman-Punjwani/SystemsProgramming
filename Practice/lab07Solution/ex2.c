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
		sleep(2);
		execlp("ps", "ps", "-f", (char *)NULL);
	default:
		exit(0);
	}
}
