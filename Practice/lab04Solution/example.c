#include <stdio.h>
#include <errno.h>

int main()
{
	printf("\n\t Value of errno : %d \n", errno);
	perror("\t At the start of prog.");

	return 0;
}    
