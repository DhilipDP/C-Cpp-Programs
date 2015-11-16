#include <iostream>
#include<vector>
#include<limits.h>

using namespace std;



int LIS(vector<int> v)
{
	int n = v.size() ;
	if(n==0)
		return 0;
	int maxi = 0 ;
	vector<int> lis(n,1) ;
	for(int i=1 ; i<n ; i++)
	{
		for(int j=0 ; j<i ; j++)
		{
			if(arr[j] < arr[i] && lis[j]+1 < lis[i])
			{
				lis[i] = lis[j]+1;
				maxi = max(maxi,lis[i]);
			}
		}
	}
	return maxi ;
}


int edit(string x,string y,int m,int n)
{
	int dp[m+1][n+1] ;
	dp[0][0] = 0;
	for(int i=1 ; i<=n ; i++)
		dp[0][i] = i;
	for(int i=1 ; i<=m ; i++)
		dp[i][0] = i;
	for(int i=1 ; i<=m ; i++){
		for(int j=1 ; j<=n ; j++)
		{
			int left = dp[i][j-1] + 1 ;
			int top = dp[i-1][j] + 1;
			int corner = dp[i-1][j-1] + (x[i-1] != y[j-1] );
			dp[i][j] = min(left,min(top,corner)) ;
		}
	}
	return dp[m][n] ;
		
}

int main() {
	// your code goes here
	string x = "nandu" ;
	string y = "nijin" ;
	cout<<edit(x,y,x.length(),y.length()) ;
	int arr[] = {1,7,3,4,5,2} ;
	vector<int> v(arr,arr+6);
	cout<<LIS(v);
	return 0;
}
