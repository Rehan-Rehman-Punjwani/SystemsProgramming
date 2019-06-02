#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*
It prints the size of the file (in Bytes) whose filename is passed
as a cmd-line argument.
*/

int main(int argc, char **argv)
{
	struct stat st;

	if(argc < 2){
		fprintf(stderr, "\nUsage: %s <file-name>\n\n", argv[0]);
		return 1;
	}

	if(lstat(argv[1], &st)){
		perror("stat(): ");
		return 1;
	}

	fprintf(stderr, "\n\tSize of the file is: %d\n\n", st.st_size);

	return 0;
}

