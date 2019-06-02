#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

/*
Write a program that creates a file with read permissions for all, opens it in WRITE mode
and then writes a line of text into it. The name of the file to be created is passed on
the commandline.
*/

int main(int argc, char **argv)
{
	int fd;
	char buff[20] = "";

	if(argc < 2){
		fprintf(stderr, "\nProvide the filename please !!\n");
		exit(1);
	}

	fd = open(argv[1], O_CREAT | O_WRONLY, S_IRUSR | S_IRGRP | S_IROTH);
	if( fd == -1){
		perror("file creation error");
		exit(1);
	}

	sprintf(buff, "%s", "2nd Lab it is...");
	write(fd, buff, strlen(buff));

	return 0;
}
