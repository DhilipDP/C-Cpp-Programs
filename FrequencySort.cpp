#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int tests;
	scanf("%d",&tests);
	
	while(tests--){
		 int n,u;
		scanf("%d%d",&n,&u);
		int count=0;
		 int arr[n];
		 int temp[n+1];
		 for(int i=0 ; i<=n ; i++)
		 	temp[i]=0;
		while(u--){
			int l,r,val;
			scanf("%d%d%d",&l,&r,&val);
		temp[l]+=val;
		temp[r+1]-=val;
		}
		for(int i=0 ; i<n ; i++){
			count += temp[i];
			arr[i]=count;
		}
		int q;
		scanf("%d",&q);
		while(q--){
			int index;
			scanf("%d",&index);
			printf("%d\n",arr[index]);
		}
	}
}


