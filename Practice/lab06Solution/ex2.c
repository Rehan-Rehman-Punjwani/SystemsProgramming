#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	pid = fork();
	
	switch(pid){
	case -1:
		perror("fork");
		exit(1);
	case 0:
		printf("\tIn the child process\n");
		sleep(1);
		break;
	default:
		printf("\tIn the parent process\n");
		waitpid(pid, NULL, (int)NULL);
		printf("\n\tThis should be the last thing printed !!\n");
	}
	return 0;
}

