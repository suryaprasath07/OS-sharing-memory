#include <stdio.h>
#include <unistd.h>

int main()
{
    int childpid;
    int count1 = 0, count2 = 0;
    printf("before it started!\n");
    childpid = fork();

    if (childpid == 0)
    {
        printf("Child process\n");
        while (count1 < 20)
        {
            printf("child process : %d\n", count1);
            sleep(1);
            count1++;
        }
    }
    else
    {
        printf("Parent process\n");
        while (count2 < 10)
        {
            printf("parent process : %d\n", count2);
            sleep(1);
            count2++;
        }
    }
}