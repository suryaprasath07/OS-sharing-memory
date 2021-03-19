#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 1024

void fn(int number){
	while(number!=1){
		if(number%2==0){
			number=number/2;
		}else{
			number = number*3 + 1;
		}
		printf("\n%d\n",number);
	}
}

int main(int argc, char *argv[])
{
    int shmid;
    key_t key;
    char *shm;
    char *s;
    int a = 0;
    char str[10];

    key = 9876;
    shmid = shmget(key, SHSIZE, 0666); //server call to create the shared memory
    if (shmid < 0)
    {
        perror("shmget Error");
        exit(1);
    }
    shm = shmat(shmid, NULL, 0); //attaches the shared memory segment identified by shmid to the address sapce of calling process
    if (shm == (char *)-1)
    { // SHM is pointer to the shared Memory
        perror("shmat Error");
        exit(1);
    }
    for (s = shm; *s != 0; s++)
    {
        str[a]=*s;
        a++;
    }
    
    char myarray[5] = {'-', '1', '2', '3', '\0'};
    int i;
    sscanf(str, "%d", &i);
    printf("Got the Number %d",i);
    fn(i);
    printf("\n");
    *shm = "*";
    return 0;
}
