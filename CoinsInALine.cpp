#include<iostream>
#include<limits.h>
#include<vector>
using namespace std ;



int maximumMoney(int arr[],int i,int j)
{
	if(i > j)
		return 0 ;
	if(i==j)
		return arr[i] ;
	//if I choose first, opponent can choose from 	either a[i+1] or a[j]
	// if he chooses a[i+1], then maximum energy will be fun(i+2,j)
	// if he chooses a[j] , then maximum energy will be fun(i+1,j-1)
	// if he also plays smartly he will make a  move in such a way that minimises my  money
	return max(arr[i] + min(maximumMoney(arr,i+2,j) , maximumMoney(arr,i+1,j-1) ) , arr[j] + min(maximumMoney(arr,i,j-2) , maximumMoney(arr,i+1,j-1)));
}


int maximumDP(int arr[],int n)
{
    //int n = arr.size() ;
    if(n==0)
		return 0;
    vector<vector<int> > dp(n+1 , vector<int> (n+1,0)) ;
	
	for(int i=0; i<n ; i++)
		dp[i][i] = arr[i] ;
	cout<<"s";
	for(int len = 2 ; len <= n  ; len++)
	{
		for(int i=0 ; i<=n-len ; i++)
		{
			
			int j =  i+len-1 ;
			cout<<i<<" "<<j<<endl;
			int val1 = arr[i] + min(dp[i+2][j],dp[i+1][j-1] ) ;
			int val2 = arr[j] + min(dp[i][j-2],dp[i+1][j-1] ) ;
			dp[i][j] = max(val1,val2) ;
		}
	}
	return dp[0][n-1] ;
}

int main()
{
	int arr[] = {3,4,1,5} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	cout<<maximumMoney(arr,0,n-1) ;
	cout<<endl<<maximumDP(arr,n);
}
