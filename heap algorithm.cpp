#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<fstream>
using namespace std;

struct node 
{
	string s;
	int count;
};


bool comp(struct node a,struct node b)
{
	if(a.count<b.count)
		return true;
	if(a.count==b.count)
		return a.s>b.s;
	return false;
}
int main()
{
	FILE *fp;
	fp=fopen("myfile.txt","r");
	map<string ,int >m;
	char a[100];
	while(fscanf(fp,"%s",a)!=EOF)
	{
		string s(a);
		if(m.count(s)>0)
		m[s]++;
		else
		m[s]=1;
	}
	struct node root[m.size()];
	int i=0;
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++,i++)
	root[i].s=it->first,root[i].count=it->second;
	make_heap(root,root+i,comp);
	for(int j=0;j<10;j++)
	{
		pop_heap(root,root+i-j,comp);
		cout<<root[i-j-1].count<<" "<<root[i-j-1].s<<endl;
	}
}

