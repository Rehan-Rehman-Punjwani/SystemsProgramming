#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	pid = fork();

	if (pid == -1){
		perror("fork");
		exit(1);
	} else if (pid == 0){
		printf("\tChild's PID: %d\n", getpid());
		printf("\tParent's PID: %d\n\n", getppid());
	} else {
		printf("\tParent's PID: %d\n", getpid());
		printf("\tParent's Parent's PID: %d\n", getppid());
		sleep(1);
	}

	return 0;
}
