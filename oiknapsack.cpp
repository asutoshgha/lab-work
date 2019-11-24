#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cout<<"Enter no. of objects:\n";
	cin>>n;
	int p[n];
	int w[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter weight of object "<<i+1<<":\n";
		cin>>w[i];
		cout<<"Enter profit of object "<<i+1<<":\n";
		cin>>p[i];
	}
	int W;
	cout<<"Enter weight of sack:\n";
	cin>>W;
	int m[n+1][W+1];
	for(int i=0;i<=n;i++)
	{
		m[i][0]=0;
	}
	for(int i=0;i<=W;i++)
	{
		m[0][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(j<w[i-1])
			{
				m[i][j]=m[i-1][j];
			}
			else
			{
                m[i][j]=max(m[i-1][j],p[i-1]+m[i-1][j-w[i-1]]);
			}
		}
	}
	int res=m[n][W];
	cout<<"The max. profit obtained is "<<res<<" with weights ";
	for(int i=n;i>0&&res>0;i--)
	{
		if(res==m[i-1][W])
			continue;
		else
		{
			cout<<w[i-1]<<" ";
			res-=p[i-1];
			W-=w[i-1];
		}
	}
	cout<<endl;
}
