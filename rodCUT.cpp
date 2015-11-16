#include<iostream>

using namespace std ;


int rodCut(int arr[],int n)
{
	if( n<=0)
		return 0;
	cout<<n<<endl;
	int res = -1 ;
	for(int i=0 ; i<n ; i++)
		res = max(rodCut(arr,n-i-1) + arr[i] , res);
		
	return res;	
}

int maxRodCut(int arr[],int n)
{
	int dp[n+1];
	dp[0] = 0;
	for(int i=1 ; i<=n ; i++)
	{
		dp[i] = -1 ;
		for(int j=0 ; j<i ; j++)
			dp[i] = max(dp[i] , arr[j] + dp[i-j-1]);
	}
	
	for(int i=0 ; i<=n ; i++)
		cout<<dp[i]<<" ";
	cout<<endl;
	return dp[n];
}

int main()
{
	int arr[] = {3,5} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<rodCut(arr,n)<<endl<<maxRodCut(arr,n)<<endl ;
	
	
}
