#include<iostream>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>

using namespace std;

int main(int argc,char* argv[])
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		int j=0;
		FILE *fp;
		char word[50];
		for(int i=0;argv[1][i]!='\0';i++)
		{
			word[i]=argv[1][i];
			j++;
		}
		word[j]='\0';
		fp=fopen("test.txt","w");
		for(int i=0;word[i]!='\0';i++)
		{
			putc(word[i],fp);
		}
		fclose(fp);
		cout<<"\nChild Process Completed.....\n";
	}
	else
	{
		waitpid(pid,NULL,0);
		int n,flag=0;
		cout<<"Enter the number :";
		cin>>n;
		if(n>0)
		{
			if(n==1)
				cout<<"\nNeither prime nor composite....";
			else
			{
				for(int i=2;i<n/2;i++)
				{
					if(n%i==0)
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
					cout<<"\nPrime Number";
				else
					cout<<"\nNot a prime number";
			}
		}

		cout<<"\nParent Process Completed\n";


	}

	return 0;
}

