#include<iostream>
using namespace std;
void calc(int *par,int *prflag,int *panum,string *pname,int n1,int n2)
{	cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\nPROCESS\tPARTITION\n";
	for(int i=0;i<n2;i++)
	{
		if(prflag[i]==1)
			cout<<"\n"<<pname[i]<<"\t"<<panum[i]<<"\n ";
		else
			cout<<"\n"<<pname[i]<<"\tno partition\n";
	}
	cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	/*cout<<"\nRemaining Memory in Partitions :\n";
	for(int i=0;i<n1;i++)
	{
		cout<<"Pratition "<<(i+1)<<" : "<<par[i]<<"\n";
	}*/
}
void FirstFit(int *par,int *pro,string *pname,int n1,int n2)
{
	int paflag[n1],rmem[n1],prflag[n2],ct=0,panum[n2];
	for(int i=0;i<n1;i++)
		paflag[i]=0;
	for(int i=0;i<n2;i++)
	{
		panum[i]=-1;

		prflag[i]=0;
	}
	for(int i=0;i<n2;i++)
	{
		for(int j=0;j<n1;j++)
		{
			if(pro[i]<=par[j] && paflag[j]!=1)
			{
				par[j]-=pro[i];
				panum[i]=j+1;
				paflag[j]=1;
				prflag[i]=1;ct++;
				break;
			}
		}
	}
	calc(par,prflag,panum,pname,n1,n2);
}
void BestFit(int *par,int *pro,string *pname,int n1,int n2)
{
	int paflag[n1],rmem[n1],prflag[n2],panum[n2],ct=0,flag,min;
	for(int i=0;i<n1;i++)
		paflag[i]=0;
	for(int i=0;i<n2;i++)
	{
		panum[i]=-1;
		prflag[i]=0;
	}
	for(int i=0;i<n2;i++)
	{
		flag=0;min=-1;
		for(int j=0;j<n1;j++)
		{
			if(flag==0)
			{
				if(par[j]>=pro[i] && paflag[j]!=1)
				{
					min=j;
					flag=1;
				}
			}
			else
			{
				if(par[j]>=pro[i] && par[j]<par[min] && paflag[j]!=1)
				{
					min=j;
				}
			}
		}
		if(min!=-1)
		{
			paflag[min]=1;
			prflag[i]=1;
			panum[i]=min+1;
			par[min]-=pro[i];
		}
	}
	calc(par,prflag,panum,pname,n1,n2);
}
void WorstFit(int *par,int *pro,string *pname,int n1,int n2)
{
	int paflag[n1],rmem[n1],prflag[n2],panum[n2],ct=0,flag,max;
	for(int i=0;i<n1;i++)p1		512
p2		212
p3		432
p4		101
		paflag[i]=0;
	for(int i=0;i<n2;i++)
	{
		panum[i]=-1;
		prflag[i]=0;
	}
	for(int i=0;i<n2;i++)
	{
		flag=0;max=-1;
		for(int j=0;j<n1;j++)
		{
			if(flag==0)
			{
				if(par[j]>=pro[i] && paflag[j]!=1)
				{
					max=j;
					flag=1;
				}
			}
			else
			{
				if(par[j]>=pro[i] && par[j]>par[max] && paflag[j]!=1)
					max=j;
			}
		}
		if(max!=-1)
		{
			paflag[max]=1;
			prflag[i]=1;
			panum[i]=max+1;
			par[max]-=pro[i];
		}
	}
	calc(par,prflag,panum,pname,n1,n2);
}
int main()
{
	int n1,n2,c;
	cout<<"Enter the number of partitions: ";
	cin>>n1;
	int par[n1];
	for(int i=0;i<n1;i++)
	{
		cout<<"Partition "<<(i+1)<<" : ";
		cin>>par[i];
	}
	cout<<"Enter the number of processes : ";
	cin>>n2;
	int pro[n2];
	string pname[n2];
	cout<<"Process\t\tSize \n";
	for(int i=0;i<n2;i++)
	{
		cin>>pname[i];
		cin>>pro[i];
	}
	cout<<"\n\n1.First Fit\n2.Best Fit\n3.Worst Fit\nEnter your choice : ";
	cin>>c;
	switch(c)
	{
		case 1 :FirstFit(par,pro,pname,n1,n2);
			break;
		case 2 :BestFit(par,pro,pname,n1,n2);
			break;
		case 3 :WorstFit(par,pro,pname,n1,n2);
			break;
		default:cout<<"\nSorry !!! Wrong Choice.....\n";
			break;
	}


	return 0;
}
