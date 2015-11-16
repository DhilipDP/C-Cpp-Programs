#include<iostream>

using namespace std  ;


int main()
{

	int t ; cin>>t ;
	while(t--)
	{
		int n ; cin>>n;
		int arr[n] ,dp[n];
		for(int i=0 ; i<n ; i++) 
		{
		cin>>arr[i];
		dp[i] = 1;
		}
	
		for(int i=1 ; i<n ; i++)
		{
			for(int j=0 ; j<i ; j++)
			{
				int val = (arr[j] * arr[i])/(arr[j] + arr[i]);
				if(val > d)
			}
		}
	}
}
