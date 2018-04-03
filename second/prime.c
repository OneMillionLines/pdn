#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
  int a,b=0,c,i;
   FILE *f;
f=fopen("f.txt","w");
printf(" enter a num");
scanf("%d",&a);
    pid_t pid;
    pid=fork();
        if(pid==0)
 	{
          if(f==0)
          {
	     printf("no file");
             return 0;
           }
		printf("\nchild ");
	   fprintf(f,"%d",a);
		printf("\nchild ends");
          fclose(f);
  	 }
         else	
	{
	    printf("\nparent..\n ");
            for(i=2;i<=a/2;i++)
         	{
			if(a%i==0)
                         {
				b=1;
				break;
			}
                 }
            if(b==1)
            printf("\n given num is prime ");
            else
         	printf("\n given num not is prime ");
            wait(NULL);
            printf("\n parent completed");
      }

}
            
            
                         	
         

