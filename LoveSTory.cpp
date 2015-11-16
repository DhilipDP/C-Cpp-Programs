#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


bool check(long long arr[],int n,long long sum){
	for(int i=0 ; i<n ; i++){
		int left = i+1;
		int right = n-1;
		while(right > left){
			if(arr[i] + arr[left] + arr[right] == sum  )
			{
				if(arr[i]!=arr[left] && arr[i]!=right && arr[left]!=arr[right])
					return true;
			}
			else if(arr[i] + arr[left] + arr[right] > sum)
				right --;
			else
				left++;
			
		}
	}
	return false;
}

int compare(const void * a,const void * b){
	return (long long *)a - (long long *)b;
}
int main()
{
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int n,i;
		scanf("%d",&n);
		long long arr[n];
		for(i=0 ; i<n ; i++)
			scanf("%lld",&arr[i]);
		long long p;
		scanf("%lld",&p);
		qsort(arr,n,sizeof(long long),compare);
		if(check(arr,n,p))
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	return 0;
}
