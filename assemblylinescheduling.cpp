#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cout<<"Enter no. of stations:\n";
	cin>>n;
	int a1[n],a2[n],t1[n-1],t2[n-1];
	int f1[n],f2[n];
	int e1,e2,x1,x2;
	cout<<"Enter entry and exit time for line 1:\n";
	cin>>e1>>x1;
	cout<<"Enter entry and exit time for line 2:\n";
	cin>>e2>>x2;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter cost for station "<<i+1<<" of line 1:\n";
		cin>>a1[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Enter cost for station "<<i+1<<" of line 2:\n";
		cin>>a2[i];
	}
	for(int i=0;i<n-1;i++)
	{
		cout<<"Enter transfer cost from station "<<i+1<<" of line 1 to station "<<i+2<<" of line 2:\n";
		cin>>t1[i];
	}
	for(int i=0;i<n-1;i++)
	{
		cout<<"Enter transfer cost from station "<<i+1<<" of line 2 to station "<<i+2<<" of line 1:\n";
		cin>>t2[i];
	}
	f1[0]=a1[0]+e1;
	f2[0]=a2[0]+e2;
	for(int j=1;j<n;j++)
	{
		f1[j]=min(f1[j-1]+a1[j],f2[j-1]+t2[j-1]+a1[j]);
		f2[j]=min(f2[j-1]+a2[j],f1[j-1]+t1[j-1]+a2[j]);
	}
	int c=min(f1[n-1]+x1,f2[n-1]+x2);
	cout<<"Min time taken is "<<c<<endl;
}
