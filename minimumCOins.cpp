#include<iostream>
#include<limits.h>

#include<vector>
using namespace std ;

int minimumCoins(vector<int> &v,int n,int cost)
{
	if( cost < 0 )
		return INT_MAX ;
	if( cost == 0)
		return 0;
	int c = INT_MAX ;
	for(int j=0 ; j<n ; j++)
		c = min(c,minimumCoins(v,n,cost-v[j]));
	return c+1;
}
/*
int minCoins(vector<int> v,int cost)
{
	int n = v.size() ;
	vector<int> dp(cost+1);
	dp[0] = 0;
	for(int i=1 ; i<=cost ; i++)
	{
		int c = INT_MAX ;
		for(int j=0 ; j<n ; j++)
			if(i >= v[j])
				c = min(c , dp[i-v[j]]);
		if(c!=INT_MAX)
			dp[i] = c+1;
	}
	return dp[cost];
}
*/

vector<int> fib ;

int minCoins(int cost)
{
	int n = fib.size() ;
	vector<int> dp(cost+1);
	dp[0] = 0;
	for(int i=1 ; i<=cost ; i++)
	{
		int c = INT_MAX ;
		for(int j=0 ; j<n ; j++)
			if(i >= fib[j])
				c = min(c , dp[i-fib[j]]);
		if(c!=INT_MAX)
			dp[i] = c+1;
	}
	return dp[cost];
}
void init(int N)
{
    fib.push_back(1);
    fib.push_back(1);
    int num = 1;
    int i=2;
    while(num <= N){
        num = fib[i-1] + fib[i-2];
        fib.push_back(num);
        i++;
        
    }
}



int fibsum(int A) {
    init(A);
    for(int i=0 ; i<fib.size() ; i++)
    	cout<<fib[i]<<" ";
    cout<<endl<<minCoins(A);
}

int main()
{
	fibsum(7);
	int arr[] = {1,3,9,10} ;
	int n  = sizeof(arr)/sizeof(arr[0]) ;
	vector<int> v(arr,arr+n) ;
//	cout<<minimumCoins(v,n,15)<<endl<<minCoins(v,15) ;
	
	
}
