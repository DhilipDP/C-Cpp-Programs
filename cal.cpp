#include<iostream>
using namespace std;

int main(){
	int amt;
	cin>>amt;
	int n;
	cin>>n;
	int i,j;
	int arr[n][n];
	int dp[n][n];
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			cin>>arr[i][j],dp[i][j]=0;
	dp[0][0] = arr[0][0];
	int sr=0,sc=0;
	for(i=1 ; i<n ; i++)
		dp[0][i] = arr[0][i]+dp[0][i-1];
	for(j=1 ; j<n ; j++)
		dp[j][0] = arr[j][0] + dp[j-1][0];
 	for(i=1 ; i<n ; i++){
		for(j=1 ; j<n ; j++){
			int val1 = dp[i-1][j]+arr[i][j];
			int val2 = dp[i][j-1]+arr[i][j];
			dp[i][j] = min(val1,val2);
 		}
	}
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}

	int v = dp[n-1][n-1];
	if(v <= amt)
		cout<<"YES "<<v;
	else
		cout<<"NO "<<-(amt-v);

}
