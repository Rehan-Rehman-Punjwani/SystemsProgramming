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
	struct shm_st shm;

	if((shm_id = shmget(123, sizeof(struct shm_st), 0666|IPC_CREAT)) == -1){
		perror("shmget");
		exit(1);
	}

	if((shm = shmat(shm_id, NULL, 0)) == (struct shm_st *)-1){
		perror("shmat");
		exit(1);
	}

	strcpy(shm.buf, "Get busy living, or get busy dying...");

	/***  CleanUP !!  ***/
	while(1){
		if(shm->flag){
			if(shmdt(shm) == -1){
				perror("shmdt");
				exit(1);
			}

			if(shmctl(shm_id, IPC_RMID, NULL) == -1){
				perror("shmctl");
				exit(1);
			}
		}

		sleep(2);
	}

	return 0;
}
