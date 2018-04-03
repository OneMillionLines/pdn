#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct proc
{
	string id;
	int bt, at;
};

bool comp(const proc a, const proc b)
{
	if (a.at < b.at) return true;
	return false;
}

void updateRR(double * rr, proc * arr, int t, int n, bool * finished)
{
	int i;
	for (i=0; i<n; i++)
	{
		if (!finished[i] && arr[i].at <= t) rr[i] = (double)(t-arr[i].at+arr[i].bt)/arr[i].bt;
	}
}

int findMax(double * rr, proc * arr, bool * finished, int t, int n)
{
	int m = -1, i;
	for (i=0; i<n; i++)
	{
		if (!finished[i] && arr[i].at <= t)
		{
			if (m == -1) m = i;
			else if (rr[i] > rr[m]) m = i;
		}
	}
	
	return m;
}

void printRR(double * rr, bool * finished, int n)
{
	int i;
	for (i=0; i<n; i++) 
	{
		if (!finished[i] && rr[i] != 0) printf("%.2lf ",rr[i]);
		else cout << "   x ";
	}
}

int main()
{
	int n, i;
	
	cout << "Enter no. of processes...";
	cin >> n;
	
	proc arr[n];
	double rr[n];
	int wt[n], tat[n], ct[n];
	bool finished[n];
	
	cout << "Enter process ID, burst time, arrival time...\n";
	
	
	for (i=0; i<n; i++) 
	{
		cin >> arr[i].id >> arr[i].bt >> arr[i].at;
		finished[i] = false;
		rr[i] = 0;
	}
	
	sort(arr,arr+n,comp);
	
	int f = 0;
	int t = 0, m;
	
	vector <int> seq;
	
	cout << endl;
	
	cout << "CT\t";
	for (i=0; i<n; i++) printf("%4s ",arr[i].id.c_str());
	cout << endl;
	
	while (f < n)
	{
		updateRR(rr,arr,t,n,finished);
		m = findMax(rr,arr,finished,t,n);
		if (m == -1) t++;
		else
		{
			cout << t << "\t";
			printRR(rr,finished,n); cout << endl;
			finished[m] = true;
			t += arr[m].bt;
			ct[m] = t;
			wt[m] = ct[m] - arr[m].bt - arr[m].at;
			tat[m] = ct[m] - arr[m].at;
//			cout << ct[m] << endl;
			f++;
			seq.push_back(m);

		}
	}
	
	cout << t << "\t";
	printRR(rr,finished,n); cout << endl;
	
	cout << "\nOrder of execution...\n";
	for (i=0; i<n; i++) cout << arr[seq[i]].id << " ";
	
	int wtSum = 0, tatSum = 0;
	
	cout << "\n\nProcess\tWT\tTAT\n";
	for (i=0; i<n; i++) 
	{
		cout << arr[i].id << "\t" << wt[i] << "\t" << tat[i] << endl;
		wtSum += wt[i];
		tatSum += tat[i];
	}
	
	cout << "\nAVG WT: " << (double)wtSum/n << endl << "AVG TAT: " << (double)tatSum/n << endl;
	
	

	
	return 0;
}

