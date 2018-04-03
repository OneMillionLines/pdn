#include<bits/stdc++.h>
using namespace std;
struct process
{	string pname;
	int atime,stime,ratio;
};
void sorting(process *p,int n)
{	process temp;
	for(int i=0;i<n-1;i++)
	{	for(int j=i+1;j<n;j++)
		{	if(p[j].atime<p[i].atime)
			{	temp=p[j];p[j]=p[i];p[i]=temp;;
			}
		}
	}
}
void calculate(process *p,int *tatime,float ttatime,int n)
{
	cout<<"\n\nProcesses\tTurn Around Time\n";
	for(int i=0;i<n;i++)
	{
		cout<<p[i].pname<<"\t\t"<<tatime[i]<<"\n";
	}
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	//cout<<"\nAverage Waiting Time = "<<(twtime/n);
	cout<<"\nAverage Turn Around Time = "<<(ttatime/n);
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
void nps(process *p,int n)
{
	int wtime[n],tatime[n],processtime=0,index=0,flag;
	float twtime=0,ttatime=0,ratio1[n];
	sorting(p,n);
	cout<<"\nGantt Chart :\n";
	processtime=p[0].atime;
	for(int i=0;i<n;i++)
	{	
		flag=0;
		for(int j=0;j<n;j++)
		{	ratio1[j]=float((processtime-p[j].atime+p[j].stime)/p[j].stime);
			if(flag==0)
			{
				if(p[j].atime<=processtime)
				{
					index=j;
					flag=1;
				}
			}
			else
			{
				if(p[j].atime<=processtime && ratio1[j]>=ratio1[j])
					index=j;
			}
		}
		p[index].ratio=ratio1[index];
		processtime+=p[index].stime;
		tatime[index]=processtime-p[index].atime;
		ttatime+=float(tatime[index]);
		p[index].atime=INT_MAX;
	}
	cout<<processtime<<"\n\n";
	calculate(p,tatime,ttatime,n);
}


/*void ps(process *p,int n)
{


}
*/

int main()
{	int n,ch;
	cout<<"\nenter no of process:";
	cin>>n;
	process p[n],temp;
	cout<<"\nprocess\t\taraival time\t\tservice time\n";
	for(int i=0;i<n;i++)
	{	cin>>p[i].pname>>p[i].atime>>p[i].stime;
	}
	cout<<"\n1.NON-PREMPTIVE\t2.PREMPTIVE\t3.EXIT\nenter your choice:";
	cin>>ch;
	while(1)
	{
		switch(ch)
		{
			case 1:	cout<<"\n non premptive";
					nps(p,n);
					break;
			case 2: cout<<"\npremptive";
			//		ps(p,n);
					break;
			case 3: exit(0);
		}
	}
	return 0;
		
}			
