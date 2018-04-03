#include<bits/stdc++.h>
using namespace std;
struct process
{
	string pname;
	int btime,atime,pri,extime;
};
void sorting(process *p,int n)
{
	process temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[j].atime==p[i].atime)
			{
				if(p[j].btime<p[i].btime)
				{
					temp=p[j];p[j]=p[i];p[i]=temp;
				}
			}
			if(p[j].atime<p[i].atime)
			{
				temp=p[j];p[j]=p[i];p[i]=temp;
			}
		}
	}
}
void calculate(process *p,int *wtime,int *tatime,float twtime,float ttatime,int n)
{
	cout<<"\n\nProcesses\tWaiting Time\tTurn Around Time\n";
	for(int i=0;i<n;i++)
	{
		cout<<p[i].pname<<"\t\t"<<wtime[i]<<"\t\t"<<tatime[i]<<"\n";
	}
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\nAverage Waiting Time = "<<(twtime/n);
	cout<<"\nAverage Turn Around Time = "<<(ttatime/n);
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
void FCFS(process *p,int n)
{
	int wtime[n],tatime[n],processTime=0;
	float twtime=0,ttatime=0;
	sorting(p,n);
	cout<<"\nGantt Chart :\n";
	processTime=p[0].atime;
	for(int i=0;i<n;i++)
	{
		cout<<processTime<<" <->"<<p[i].pname<<" <-> ";
		wtime[i]=processTime-p[i].atime;
		twtime+=float(wtime[i]);
		processTime+=p[i].btime;
		tatime[i]=processTime-p[i].atime;
		ttatime+=float(tatime[i]);
		p[i].atime=INT_MAX;
	}
	cout<<processTime<<"\n";
	calculate(p,wtime,tatime,twtime,ttatime,n);
}
void sjf(process *p,int n)
{
	int wtime[n],tatime[n],processTime=0,index=0,flag;
	float twtime=0,ttatime=0;
	sorting(p,n);
	cout<<"\nGantt Chart :\n";
	processTime=p[0].atime;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for(int j=0;j<n;j++)
		{	
			if(flag==0)
			{
				if(p[j].atime<=processTime)
				{
					index=j;
					flag=1;
				}
			}
			else
			{
				if(p[j].atime<=processTime && p[j].btime<=p[index].btime)
					index=j;
			}
		}
		cout<<processTime<<" <-> "<<p[index].pname<<" <-> ";
		wtime[index]=processTime-p[index].atime;
		twtime+=float(wtime[index]);
		processTime+=p[index].btime;
		tatime[index]=processTime-p[index].atime;
		ttatime+=float(tatime[index]);
		p[index].atime=INT_MAX;
	}
	cout<<processTime<<"\n\n";
	calculate(p,wtime,tatime,twtime,ttatime,n);
}
void priority(process *p,int n)
{
	int wtime[n],tatime[n],processTime=0,index=0,flag;
	float twtime=0,ttatime=0;
	sorting(p,n);
	cout<<"\nGantt Chart :\n";
	processTime=p[0].atime;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for(int j=0;j<n;j++)
		{	
			if(flag==0)
			{
				if(p[j].atime<=processTime)
				{
					index=j;
					flag=1;
				}
			}
			if(p[j].atime<=processTime && p[j].pri<=p[index].pri)
			{
				if(p[j].pri==p[index].pri)
				{
					if(p[j].atime<=p[index].atime)
						index=j;
				}
				else
					index=j;
			}
		}
		cout<<processTime<<" <-> "<<p[index].pname<<" <-> ";
		wtime[index]=processTime-p[index].atime;
		twtime+=float(wtime[index]);
		processTime+=p[index].btime;
		tatime[index]=processTime-p[index].atime;
		ttatime+=float(tatime[index]);
		p[index].atime=INT_MAX;
	}
	cout<<processTime<<"\n";
	calculate(p,wtime,tatime,twtime,ttatime,n);
}
void Psjf(process *p,int n)
{	cout<<"enter";
	int wtime[n],tatime[n],processTime=0,index=0,flag,count=0;
	string ch;
	float twtime=0,ttatime=0;
	processTime=p[0].atime;
	while(count<n)
	{
		flag=0;
		for(int j=0;j<n;j++)
		{	
			if(flag==0)
			{
				if(p[j].atime<=processTime)
				{
					index=j;
					flag=1;
				}
			}
			else
			{
				if(p[j].atime<=processTime && p[j].btime<=p[index].btime)
					index=j;
			}
		}
		if(ch.compare(p[index].pname)!=0)
			cout<<processTime<<" <-> "<<p[index].pname<<" <-> ";
		p[index].extime++;
		processTime++;
		ch=p[index].pname;
		if(p[index].extime==p[index].btime)
		{
			wtime[index]=processTime-p[index].extime-p[index].atime;
			twtime+=float(wtime[index]);
			tatime[index]=processTime-p[index].atime;
			ttatime+=float(tatime[index]);
			p[index].atime=INT_MAX;
			count++;
		}
	}
	cout<<processTime<<"\n";
	calculate(p,wtime,tatime,twtime,ttatime,n);
}
int main()
{
	int n,ch;
	cout<<"Enter number of processes : ";cin>>n;
	process p[n],temp;
	cout<<"\nProcess\tBurst Time\tArrival Time\tpriority\n";
	for(int i=0;i<n;i++)
	{
		cin>>p[i].pname>>p[i].btime>>p[i].atime>>p[i].pri;
		p[i].extime=0;
	}
	//while(1)
	//{
	cout<<"1.FCFS Scheduling\n2.sjf Scheduling\n3.priority Scheduling\n4.Preemptive sjf Scheduling\n5.exit\nEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1://cout<<"\nFCFS Scheduling:\n\n";
			FCFS(p,n);
			break;
		case 2://cout<<"\nsjf Scheduling:\n\n";
			sjf(p,n);
			break;
		case 3://cout<<"\npriority Scheduling:\n\n";
			priority(p,n);
			break;
		case 4://cout<<"\nPreenptive sjf Scheduling:\n\n";
			Psjf(p,n);
			break;
		case 5:exit(0); 
		default:cout<<"\nSorry !!! Wrong Choice........\n";
			break;
	}
	//}
	return 0;
}
