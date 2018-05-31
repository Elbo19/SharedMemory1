#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <time.h>
int main(){
int shmid;
int *num;
int key;
key = 7777;
int r;
	if ((shmid = shmget(key, sizeof(int) , IPC_CREAT | 0666)) < 0) {	
		printf("error creating shared memory segment\n");
		exit(1);
	}
	if((num = shmat(shmid, NULL, 0)) == (int *) -1){
		printf("error attaching shared memory segment\n");
		exit(1);
	}
	srand(time(NULL));
	r = rand() % 10;
	*num = r;
	shmdt(num);
}
