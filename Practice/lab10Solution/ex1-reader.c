#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

struct shm_st{
	char buf[50];
	int flag;
};


int main()
{
	int shm_id;
	struct shm_st *shm;

	if((shm_id = shmget(123, sizeof(struct shm_st), 0444)) == -1){
		perror("shmget");
		exit(1);
	}

	if((shm = shmat(shm_id, NULL, 0)) == (struct shm_st *)-1){
		perror("shmat");
		exit(1);
	}

	fprintf(stderr, "\n\tText from the Writer follows...\n");
	fprintf(stderr, "\t%s\n\n", shm->buf);

	shm->flag = 1;
	if(shmdt(shm) == -1){
		perror("shmdt");
		exit(1);
	}

	return 0;
}
