#include<iostream>
#include<stdlib.h>
using namespace std ;

int main(){
	
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	int dp[k+1][n];
	for(int i=0;i<=k;i++)
		for(int j=0 ; j<n ; j++)
			dp[i][j] = 0;
	
	for(int i=0;i<n;i++){
		int j=i+1;
		if(j!=a && abs(a-j) < abs(b-a) )
			dp[1][i] = 1;
	}
	for(int i=2 ; i<=k ; i++)
	{
		for(int j=0 ; j<n ; j++){
			
			if(dp[i-1][j]!=0){
				int x=j+1;
				for(int l=0 ; l<n ; l++)
				{
					int y=l+1;
					if(y!=x && abs(x-l) < abs(b-x))
						dp[i][j] = 1;
				}
			}
		
		}
	}
	int sum = 0;
	for(int i=0 ; i<n ; i++){
		sum = (sum+ dp[k][i])%1000000007;
	}
	cout<<sum;
}
