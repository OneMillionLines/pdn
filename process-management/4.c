#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char* argv[])
{
	int a=0, b=1, n=a+b,i,n1;
	pid_t pid = fork();
	if (pid == 0)
	{	n1=0;
		for(i=0;argv[1][i]!='\0';i++)
			n1=(n1*10)+(argv[1][i]-'0');
		i=n1-2;
		printf("Child is making the Fibonacci\n");
	    printf("0 %d",n);
	    while (i>0) 
	    {
	      	n=a+b;
	        printf(" %d", n);
	        a=b;
	        b=n;
	        i--;
	        if (i == 0) 
	        {
	            printf("\nChild ends\n");
	        }
	    }
	}
	else 
	    {
	        printf("Parent is waiting for child to complete...\n");
	     
	        //waitpid(pid, NULL, 0);
	        printf("Parent ends\n");
	    }
    return 0;
}	
