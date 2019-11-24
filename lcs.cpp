include<iostream>
#include<string.h>
using namespace std;

char c[50][50];

void print(char s[],int i,int j)
{
	if(i==0||j==0)
	{
		return;
	}
	else
	{
		if(c[i][j]=='d')
		{
			print(s,i-1,j-1);
			cout<<s[i-1];
		}
		else if(c[i][j]=='u')
		{
			print(s,i-1,j);
		}
		else
		{
			print(s,i,j-1);
		}
	}
}

int main()
{
	char s1[101],s2[101];
	cout<<"Enter 2 strings:\n";
	cin>>s1>>s2;
	int m=strlen(s1);
	int n=strlen(s2);
	int l[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		l[i][0]=0;
	}
	for(int j=0;j<=n;j++)
	{
		l[0][j]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				l[i][j]=1+l[i-1][j-1];
				c[i][j]='d';
			}
			else if(l[i-1][j]>=l[i][j-1])
			{
				l[i][j]=l[i-1][j];
				c[i][j]='u';
			}
			else
			{
				l[i][j]=l[i][j-1];
				c[i][j]='l';
			}
		}
	}
    cout<<"The longest common subsequence is ";
    print(s1,m,n);
    cout<<" of length "<<l[m][n]<<endl;
}
