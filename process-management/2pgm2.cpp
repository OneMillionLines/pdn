#include<iostream>
#include<math.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;
int rev(int n)
{
	int a,val=0;
	while(n>0)
	{
		a=n%10;
		n=n/10;
		val=val*10+a;
	}
	return val;
}
int main(int argc,char *argv[])
{
	int n=0;
	for(int i=0;argv[1][i]!='\0';i++)
		n=(n*10)+(argv[1][i]-'0');
	
	pid_t pid;
	pid=fork();
	
	if(pid==0)
	{
		int val=0,a,ct=0,value;
		while(n>0)
		{
			a=n%2;
			n=n/2;
			if(val==0 && a==0)
				ct++;
			val=val*10+a;
		}
		value=rev(val);
		if(ct>0)
			value=value*(int)pow(10,ct);
		cout<<"\n\nBinary Value = "<<value;
		cout<<"\nChild Process Completed......";
	}
	else
	{
		int value,val=0,a;
		wait(NULL);
		while(n>0)
		{
			a=n%8;
			n=n/8;
			val=val*10+a;
		}
		value=rev(val);
		cout<<"\n\nOctal Value = "<<value;
		cout<<"\nParent Process Completed......";
	}
	return 0;
}
