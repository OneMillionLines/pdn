#include<iostream>
using namespace std;
int main()
{
	int i;
	start:
	for(i=0;i<100000;i++)
		cout<<"";
	for(i=0;i<5;i++)
		cout<<"\n"<<i;
	goto start;
	return 0;
}
