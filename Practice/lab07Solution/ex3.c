#include <stdio.h>
#include <signal.h>

int main()
{
	sigset_t set;

	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGTSTP);
	
	if(sigprocmask(SIG_SETMASK, &set, NULL) == -1)
		perror("sigprocmask");

	while(1){
		fprintf(stderr, "ZzzZZz...\t");
		sleep(2);
	}

	return 0;
}
