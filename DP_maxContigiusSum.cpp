#include<iostream>
#include<limits.h>

using namespace std ;



int maxSum(int a[] , int n){
	int dp[n];
	int cur_max = a[0] ;
	dp[0] = a[0] ;
	int i;
	for(i=1 ; i<n ; i++){
		cur_max = max(a[i],cur_max+a[i]);
		dp[i] = max(dp[i-1],cur_max);
	}
	for(i=0 ; i<n ; i++)
		cout<<dp[i]<<" ";
	cout<<endl;
	/*int sum = dp[n-1] ;
	int ans[n];
	int j,k=0 ;
	for(i=n-1 ; i>=0 && sum>0; i--){
		while(dp[i]==sum){
			i--;
		}
		ans[k]
	}
	for(i=k ; i>=0 ; i++)
		cout<<ans[i]<<" ";
	cout<<endl; */
	return dp[n-1];
}



int kadane(int *arr,int n,int &start ,int &finish){
	int sum  = 0;
	finish = -1 ;
	int cur_start = 0;
	
	int i;
	int max_sum = INT_MIN ;
	for(i=0 ; i<n  ;i++){
		sum += arr[i] ;
		if(sum < 0){
			sum = 0;
			cur_start = i+1;
		}
		else if(sum > max_sum){
			max_sum = sum ;
			start = cur_start ;
			finish = i;
		}
	}
	if(finish!=-1)
		return max_sum ;
	else{
		for(i=0 ; i<n ; i++){
			if(arr[i] > max_sum)
				max_sum = arr[i],start=finish=i;
		}
		return max_sum;
	}
}
int main(){
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<maxSum(arr,n);
	int s=0 ,f=0;
	cout<<endl<<kadane(arr,n,s,f);
	for(int i=s ; i<=f ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
