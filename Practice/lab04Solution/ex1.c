#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>

/*
Program demonstrating perror() and errno.
*/

int main()
{	
	/* 
	 * Trying to kill a process that does not exist !!
	*/
	kill(222222, 0);	
	printf("\n\t Value of errno : %d \n", errno);
	perror("\t OverKill -:^)");


	/*
	 * Trying to open a nonexistent file...
	*/
	if(fopen("RusselPeters", "r") == NULL){
		printf("\n\t Value of errno : %d \n", errno);
		perror("\t fopen");
	}

	return 0;
}
