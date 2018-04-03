#include <iostream>

using namespace std;

#define INF 100001

int findPos(int * arr, int x, int low, int high)
{
	int i;
	for (i=low; i<=high; i++) if (x == arr[i]) return i;
	return INF;
}

void print(int * mem, int n)
{
	int i;
	for (i=0; i<n; i++) cout << mem[i] << " ";
	cout << endl;
}

int main()
{

	int n, m, i, j;
	cout << "No. of frames in memory...";
	cin >> m;
	
	cout << "No. of references...";
	cin >> n;
	
	int mem[m];
	
	for (i=0; i<m; i++) mem[i] = -1;
	
	int arr[m][n];
	
	int ref[n];
	
	int pf = 0, pr = 0;
	
	cout << "Enter reference string...\n";
	for (i=0; i<n; i++) cin >> ref[i];
	
	/*
	for (i=0; i<m && i<n; i++) 
	{
		mem[i] = ref[i];
		pf++; 
	}*/
	
	for (i=0; i<n; i++)
	{
		int index = findPos(mem,ref[i],0,m-1);
		if (index == INF)
		{
			int pos, maxPos=0, maxPosP;
			for (j=0; j<m; j++) 
			{
				pos = findPos(ref,mem[j],i+1,n-1);
				if (pos > maxPos) { maxPos = pos; maxPosP = j; }
			}
			if (mem[maxPosP] != -1) pr++;
			mem[maxPosP] = ref[i];
			pf++;
			
		}
		else mem[index] = ref[i];
		
		for (j=0; j<m; j++) arr[j][i] = mem[j];
	}
	
	cout << "Page Faults: " << pf << endl << "Page Replacements: " << pr << endl;
	
	for (i=0; i<m; i++)
	{
	    for (j=0; j<n; j++) 
	        if (arr[i][j] == -1) cout << "  ";
    	   // else //cout << arr[i][j] << " ";
    		//cout << endl;
    }
	
	
	return 0;
}
