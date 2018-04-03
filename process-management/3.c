#include<stdio.h>
#include<sys/types.h>
int main()
{
    pid_t pid;
    pid_t pid1;
    pid=fork();
    if(pid<0)
        printf("Failure of fork");
    else if(pid==0)
    {
        pid1=getpid();
        printf("\nThe child process id  %d\n",pid);
        printf("\npid1:%d",pid1);	
    }
    else
    {
        pid1=getpid();
        printf("\n%d",pid);
        printf("\n%d",pid1);
    }
    return 0;
}
