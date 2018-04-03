#include<stdio.h>
#include<sys/types.h>
int main()
{
	int value=5;
	int pid=fork();
	if(pid==0)
	{	value+=15;
		//return 0;
	}
	else if(pid>0)
		wait();
	printf("\nvalue=%d",value);
	
}
