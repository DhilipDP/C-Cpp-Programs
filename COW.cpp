#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	long int n,m,p;
	scanf("%ld%ld%ld",&n,&m,&p);
	long int cow[n];
	long int bull[m];
	long int i,j;
	for(i=1 ; i<=n ; i++)
		cow[i]=0;//printf("%ld ",cow[i]);
	for(i=1 ; i<=m ; i++)
			bull[i]=0;//printf("%ld ",bull[i]);
/*	for(i=1 ; i<=n ; i++)
		printf("%d ",cow[i]);
	printf("\n");
	for(i=1 ; i<=m ; i++)
		printf("%d ",bull[i]);
	printf("\n");*/
		long int pairs=0;
	while(p--){
		long int a,b;
	//	long int pairs=0;
		scanf("%d%d",&a,&b);
		if(cow[a]==0 && bull[b]==0)
		{
		   pairs++;
		
			cow[a]=1;
			bull[b]=1;
		}	
	//	cout<<pairs<<endl;
	}
	printf("%ld",pairs);
}
