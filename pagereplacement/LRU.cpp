#include <iostream>
#include <vector>

using namespace std;

int findEarliest(int * la, int n)
{
    int i, m = 0;
    for (i=0; i<n; i++)
    {
        if (la[i] < la[m]) m = i;
    }
    return m;
}

int found(int * arr, int x, int n)
{
    int i;
    for (i=0; i<n; i++) if (arr[i] == x) return i;
    return -1;
}

void print(int * a, int * b, int n)
{
    int i;
    for (i=0; i<n; i++) cout << "(" << a[i] << ", " << b[i] << ") ";
}

void print(int * a, int n)
{
    int i;
    for (i=0; i<n; i++) cout << a[i] << " ";
}

int main()
{
    int n, m, i, j;
    int pr, pf;
    pr = pf = 0;
    
    cout << "Enter no. of pages in memory...";
    cin >> m;
    cout << "Enter no. of references...";
    cin >> n;
    
    int la[m], mem[m];
    int ref[n];
  
    for (i=0; i<m; i++) la[i] = mem[i] = -1;
    
    int arr[m][n];
      
    cout << "enter reference string...";
    for (i=0; i<n; i++)
    {
        int x, p, pos;
        cin >> x;
        if ((pos=found(mem,x,m)) == -1)
        {
            pf++;
            p = findEarliest(la,m);
            if (mem[p] != -1) pr++;
            la[p] = i;
            mem[p] = x;
        }
        else la[pos] = i;
        for (int j = 0; j<m; j++) arr[j][i] = mem[j];
    }
    
    cout << endl;
    for (i=0; i<m; i++)
    {
        cout << " ";
        for (j=0; j<n; j++) 
            if (arr[i][j] != -1) cout << arr[i][j] << " ";
            else cout << "  ";
        cout << endl;
    }
    cout << endl;
    cout << "Page Faults: " << pf << endl << "Page Replacements: " << pr << endl;
    
    return 0;
}
        
    
  
    
    
