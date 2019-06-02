#include <stdio.h>
#include <signal.h>

int main()
{
	int *ptr;
	struct sigaction sa;
	
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGSEGV, &sa, NULL);

	*ptr = 1;
	
	return 0;
}

