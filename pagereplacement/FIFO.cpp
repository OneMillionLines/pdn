#include<iostream>
#include<string.h>


using namespace std;

int find(int fra[],int num,int len)
{
	for(int i=0;i<len;++i)
	{
		if((int)fra[i]==num)
			return 1;
	}
	return 0;
}

int main()
{
	int n,st,old=0;
	int PF=0;
	int flag=1;
	int PR=0;
	int i, j, m;
	
	//cout << "Enter no. of frames in memory...";
	cin>>st;
	//cout << "Enter no. of references..."; 
	cin>>m;
	n=m;
	int str[200];
	int fra[st];
	
	int arr[st][n];
	
	for(m=0;m<st;++m)
	{
		fra[m]=-1;
	}
		
	for(i=0;i<n;++i)
	{
		cin>>str[i];
		//cout<<str[i];
	}

	
	for(j=0;j<n;++j)
	{
		if(!find(fra,str[j],st))
		{
		    if (fra[old] != -1) PR++;
			fra[old]=str[j];
			old=(old+1)%st;
			PF+=1;
			for(int l=0;l<n;++l)
			{
				//cout<<fra[l]<<'\t';
			}
		}
		//for (i=0; i<m; i++) arr[i][j] = fra[i];

	}
	
	//for (i=0; i<m; i++)
	//{
	//    for (j=0; j<n; j++)
	 //       if (arr[i][j] == -1) cout << "  ";
	//        else cout << arr[i][j] << " ";
	//}
	
	cout<<endl;
	cout<<"PageFault : "<<PF<<endl;
	cout<<"Page repl : "<<PR<<endl;
	return 0;
}
