#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t pid;
    if((pid=fork())<0)
    {
        printf("fork error!\n");
        exit(1);
    }
    else if(pid==0)
    {
        printf("in the child process!\n");
    }
    else
    {
        printf("in the parent process!\n");
    }
}

