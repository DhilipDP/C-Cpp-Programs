#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector< vector<int> > vec(n,vector<int>(n)) ;
	vector< vector<int> > temp;
	if(n!=0)
	vec[0][0]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			int sum=0;
			int ui,uj,li,lj;
			ui=i-1;
			uj=j;
			li=i-1;
			lj=j-1;
			if(ui>=0&&ui<n&&uj>=0&&uj<n)
			sum+=vec[ui][uj];
			if(li>=0&&li<n&&lj>=0&&lj<n)
			sum+=vec[li][lj];
			vec[i][j]=sum;
		}
	}
	for(int i=0;i<n;i++)
	{
		vector<int> v;
		for(int j=0;j<=i;j++)
		{
			v.push_back(vec[i][j]);	
		}
		temp.push_back(v);
	}
}
