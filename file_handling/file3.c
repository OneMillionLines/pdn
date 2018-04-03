#include<stdio.h>
main()
{
  	 int fl=0;
  
  	char ch[100];
  	char	name[100];
  	FILE *f1;
  	
  	f1=fopen("1.txt","r");
	
  	printf("\nEnter the word to be searched\n");
  	
  	scanf("\n%s",name);
  
  	while(fscanf(f1,"%s",ch)!=EOF)
  
	{
      		if(strcmp(ch,name)==0)
      		{
        		fl=1;
        		break;
      		}
     		else
     		{
       			fl=0;
     		}
	}
   
    	if(fl==0)
   
    	printf("\nAbsent\n");
   
   	else
   
   	printf("\nPresent\n");
   
   	fclose(f1);
   
   	return 0;
 }


