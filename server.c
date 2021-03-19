#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 1024

int main(int argc, char *argv[])
{
    int shmid;
    key_t key;
    char *shm;
    char *s;
    int a=100;
    char str[10];
    printf("Enter a Number : ");
    scanf("%d",&a);
    sprintf(str, "%d", a);

    key = 9876;
    shmid = shmget(key, SHSIZE, IPC_CREAT | 0666); //server call to create the shared memory
    if (shmid < 0)
    {
        perror("shmget Error");
            exit(1);
    }
    shm = shmat(shmid, NULL, 0); //attaches the shared memory segment identified by shmid to the address sapce of calling process
        if (shm == (char *)-1){ // SHM is pointer to the shared Memory
           perror("shmat Error");
           exit(1);
        }
    memcpy(shm, str, strlen(str));
    s = shm;
    s += strlen(str);
    *s = 0;
    while (*shm != '*')
    {	
    	printf("server running");
        sleep(4);
    }
    return 0;
}

