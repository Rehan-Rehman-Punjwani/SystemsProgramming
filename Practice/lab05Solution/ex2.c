#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("\n\tI am not OverWritten yet !!\n\n");

	execlp("ls", "ls", "-a", NULL);

	printf("\nThis shouldn't get printed !!");
	return 0;
}
