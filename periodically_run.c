#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    pid_t pid = 0;
    if (argc == 2)
    {
        while (1)
        {
            pid = fork();
            if (pid == 0)
            {
                char *s[] = {argv[1], NULL};
                execvp(argv[1], s);
            }
            else
            {
                wait(NULL);
            }
            sleep(2);
        }
    }
    else if (argc == 4)
    {
        if (strcmp(argv[2], "-n") == 0)
        {
            while (1)
            {
                pid = fork();
                if (pid == 0)
                {
                    char *s[] = {argv[1], NULL};
                    execvp(argv[1], s);
                }
                else
                {
                    wait(NULL);
                }
                sleep(atoi(argv[3]));
            }
        }
        else if (strcmp(argv[2], "-b") == 0)
        {
            while (1)
            {
                pid = fork();
                if (pid == 0)
                {
                    char *s[] = {argv[1], NULL};
                    if (execvp(argv[1], s) < 0)
                    {
                        perror(argv[1]);
                        sleep(2);
                        exit(1);
                    }
                    else
                    {
                        char *s[] = {argv[1], NULL};
                        execvp(argv[1], s);
                    }
                    sleep(2);
                }
                else
                {
                    wait(NULL);
                }
            }
        }
        else if (strcmp(argv[2], "-e") == 0)
        {
        }
    }
}
