#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *envp[])
{
        pid_t child;
        int i = 0;
        char *args[] = {"~/bin/ls", "ls", "/tmp", NULL};
        

        while (i < 5)
        {
                if (fork() == 0)
                {
                        execve(args[0], args, envp);
                        return(0);
                }
                i++;
        }
        i = 0;
        while (i < 5)
        {
                wait (NULL);
                i++;
        }   
}