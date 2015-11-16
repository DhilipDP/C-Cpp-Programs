#include<iostream>
#include<stdio.h>
using namespace std ;



long long int findMaxSum(long long int arr[],int n){
	long long sum[n+1] ;
	sum[0] = arr[0];
	sum[1] = max(sum[0],arr[1]);
	for(int i=2 ; i<n ; i++)
		sum[i] = max(sum[i-1],sum[i-2] + arr[i]);
	return sum[n-1];	
}

int main(){
	int t ;
	cin>>t;
	int j=1 ;
	while(t--){
		int n;
		scanf("%d",&n);
		if(n==0){
			printf("Case %d: 0\n",j++);
			continue;
		}
		long long int arr[n];
		for(int i=0; i<n ; i++)
			cin>>arr[i];
		cout<<"Case "<<j++<<": "<<findMaxSum(arr,n)<<endl;
	}

}
