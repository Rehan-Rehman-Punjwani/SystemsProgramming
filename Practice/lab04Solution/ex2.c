#include <stdio.h>

/*
A program that prints all of its environment.
*/

extern char **environ;

int main()
{
	printf("\n\t Goin to print Process Environment ...\n");


	for(; *environ; environ++){
		printf("\t%s\n", *environ);
	}

	return 0;
}
