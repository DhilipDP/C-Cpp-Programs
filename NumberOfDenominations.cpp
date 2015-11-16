#include<iostream>

using namespace std ;

int arr[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192} ;

int dp[100005] ;


int find(int sum , int n )
{

	if(dp[sum] != -1)
		return dp[sum] ;	
	if(sum == 0){
		dp[sum] = 1;
		return 1;
	}
	if(n==0){
		dp[sum] = 0;
		return 0;
	
	}
	
	int s = 0;
	if(arr[n-1] > sum){
		s = find(sum,n-1) ;
		dp[sum] = s;
		return s;
	}
	else{
	
		s = find(sum,n-1) + find(sum-arr[n-1] , n);
		dp[sum] = s;
	return s;
}

}


int main()
{
	memset(dp,-1,sizeof(dp));
	cout<<find(4,4) ;
}
