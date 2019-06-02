#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
Write a program that reads data from the shell (not from the commandline...) and then 
echoes it to the shell. End of input is indicated using the shell's EOF character (ctrl-d).
You have to use filedescriptors 0 & 1. The program should keep reading data until EOF is
passed to it.

NOTE: Bash (by default) reads input a line at a time i.e pressing 'enter' after a line would pass it to
the reading filedescriptor.
*/

int main()
{
	int nread;
	char buff[BUFSIZ] = "";

	fprintf(stderr, "\n\tInput some text, press ctrl-d when finished...\n");
	while( (nread = read(0,buff, BUFSIZ)) != 0 ){
		if( nread == -1 ){
			perror("Error reading the input...");
			exit(1);
		}

		fprintf(stderr, "\n\t%d bytes read, Echoing the text...\n", nread);

		/*NOT doing any error-checking...*/
		write(1, buff, nread);

		memset(buff, 0, BUFSIZ);
	}

	return 0;
}
