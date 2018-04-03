#include<bits/stdc++.h>

using namespace std;

int search(int arr1[],int a,int ps)
{
	int flag=0;
	for(int i=0;i<ps;i++)
	{
		if(arr1[i]==a)
			flag=1;
	}
	if(flag==1)
		return 1;
	if(flag==0)
		return 0;
}

void fifo(int arr[],int n,int ps)
{
	int pfault=0,preplace=0,arr1[ps],ct=0,temp,res;
	for(int k=0;k<ps;k++)
			arr1[k]=INT_MAX;
	for(int i=0;i<n;i++)
	{	cout<<"\n";
		if(!search(arr1,arr[i],ps))
		{	arr1[ct%3]=arr[i];
			ct++;
			if(ct>ps)
				preplace++;
			pfault++;
		}
		for(int j=0;j<ps;j++)
			cout<<arr1[j]<<"\t"; 
	}
	cout<<"\npage fault:"<<pfault;
	cout<<"\npage replacement:"<<preplace<<"\n";
}

int check(int arr[],int arr1[],int ps,int m)
{	int temp=0,pos[ps],min,min1;
	for(int i=0;i<ps;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr1[j]==arr[i])
			{
				pos[i]=j;
			}
		}
	}
	min=pos[0];
	for(int i=1;i<ps;i++)
	{
		if(pos[i]<min)
			{min=pos[i];
			min1=i;}
	}
	return min1;
}

void lru(int arr[],int n,int ps)
{
	int pfault=0,preplace=0,arr1[ps],ct=0,temp,pos;
	for(int k=0;k<ps;k++)
			arr1[k]=INT_MAX;
	for(int i=0;i<n;i++)
	{	cout<<"\n";
		if(!search(arr1,arr[i],ps))
		{		
			pos=check(arr,arr1,ps,i);
			arr1[pos]=arr[i];
			ct++;
			if(ct>ps)
				preplace++;
			pfault++;
		}
		for(int j=0;j<ps;j++)
			cout<<arr1[j]<<"\t"; 
	}
	cout<<"\npage fault:"<<pfault;
	cout<<"\npage replacement:"<<preplace<<"\n";
}

int main()
{	
	int ps,n,ch;
	cout<<"\nEnter the length of reference train:";
	cin>>n;int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"\nenter the size of primary memory:";
	cin>>ps;
	cout<<"\nEnter your choice:\n1.FIFO\n2.LRU\n3.OPT\n4.EXIT\n";
	cin>>ch;
	switch(ch)
	{
		case 1:	fifo(arr,n,ps);
				break;
		case 2:	lru(arr,n,ps);
				break;
		case 3:	//opt(arr,n,ps);
				break;
		case 4:	//exit(0);
				break;
		default:cout<<"\nwrong choice!!!";
	}		
}
