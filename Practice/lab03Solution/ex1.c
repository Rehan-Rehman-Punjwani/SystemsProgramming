#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Program that distinguishes a c-source file (having .c extension) from
other types of files.
*/

int main(int argc, char **argv)
{
	int len;
	int cntr;

	if(argc < 2){
		fprintf(stderr, "\nProvide a filename please !!\n");
		exit(1);
	}
	
	len = strlen(argv[1]);	
	for(cntr = 0; cntr < len; cntr++){
		if(argv[1][cntr] == '.' && argv[1][cntr+1] == 'c'){
			printf("\tIts a C code file.\n");
			exit(0);	
		}
	}

	printf("\tNot a C code file.\n");

	return 0;
}
