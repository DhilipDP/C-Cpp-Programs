#include<stdio.h>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int count;
	int index;
};
bool comp(struct node a,struct node b)
{
	if(a.count>b.count)
	return true;
	if(a.count==b.count)
	return a.index<b.index;
	return false;
}
int frequency(long int *a,long int n)
{
	map<int,struct node > m;
	for(int i=0;i<n;i++)
	{
		if(m.count(a[i])>0)
		{
			m[a[i]].count++;
		}
		else
		{
			struct node temp;
			temp.count=1;
			temp.index=i;
			m[a[i]]=temp;
		}
	}
	int j=0;
	struct node root[m.size()];
	for(map<int ,struct node >::iterator i=m.begin();i!=m.end();i++)
		root[j++]=i->second;
	sort(root,root+j,comp);
	for(int i=0;i<j;i++)
	{
		for(int j=0;j<root[i].count;j++)
		printf("%ld ",a[root[i].index]);
	}
}
int main()
{
	long int n, c;
	scanf("%ld",&n);
	scanf("%ld",&c);
	long int a[n];
	for(long int i=0;i<n;i++)
	scanf("%ld",&a[i]);
	frequency(a,n);
}
