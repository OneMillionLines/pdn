#include<stdio.h>
#include<sys/types.h>
int main()
{	int i=0;
	fork();
	fork();
	fork();
	i+=1;
	printf("\n%d",i);
	return 0;

}
