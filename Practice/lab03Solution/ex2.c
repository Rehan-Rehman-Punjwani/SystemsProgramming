#include <stdio.h>
#include <sys/types.h>
#include <dirent.h> 

/*
Program that gives the directory listing of the directory
whose name is passed on the command-line. 
*/

int main(int argc, char** argv)
{
	DIR * dir_ptr;
	struct dirent* dir_entry;
 
	if(argc < 2 ){
		fprintf(stderr, "\nUsage: %s dir-name\n\n", argv[0]);
		return 1;
	}

	dir_ptr = opendir(argv[1]);

	printf("\n\n");
	while(dir_entry = readdir(dir_ptr)){
		printf("%s\t", dir_entry->d_name);
	}
	printf("\n\n");

	closedir(dir_ptr);
	return 0;
}
