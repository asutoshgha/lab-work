#include<iostream>
#include<limits.h>
using namespace std;

int s[10][10];

void print(int s[10][10],int i,int j)
{
	if(i==j)
		cout<<"A"<<i<<".";
	else
	{
		cout<<"(";
		print(s,i,s[i][j]);
		print(s,s[i][j]+1,j);
		cout<<")";
	}
}

int main()
{
	cout<<"Enter no. of matrices:\n";
	int m;
	cin>>m;
	int n=m+1;
	int p[n];
	cout<<"Enter the dimensions:\n";
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	int c[n][n];
	for(int i=0;i<n;i++)
	{
		c[i][i]=0;
	}
	for(int i=0;i<n;i++)
	{
		c[i][0]=0;
	}
	for(int j=0;j<n;j++)
	{
		c[0][j]=0;
	}
	for(int d=1;d<n-1;d++)
	{
		for(int i=1;i<n-d;i++)
		{
            int j=i+d;
            int min=INT_MAX;
            for(int k=i;k<j;k++)
            {
            	int q=c[i][k]+c[k+1][j]+(p[i-1]*p[j]*p[k]);
            	if(min>q)
            	{
            		min=q;
            		s[i][j]=k;
            	}
            }
            c[i][j]=min;
		}
	}
    cout<<"The min cost is "<<c[1][n-1]<<" if the matrices are multiplied in this way:\n";
    print(s,1,n-1);
    cout<<endl;
}	
