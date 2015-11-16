#include<iostream>

#include<vector>
using namespace std;

int maximise(vector<vector<int>  >A)
{
	vector<int> v ;
	for(int i=0 ; i<A[0].size() ; i++)
	{
		int t = -1;
		for(int j=0 ; j<2 ; j++)
			t = max(t,A[j][i]);
		v.push_back(t);
	}	
	int n = v.size() ;
	for(int  i=0 ; i<n ; i++)
		cout<<v[i]<<" ";
	int dp[n+1] ;
	dp[0] = 0;
	dp[1] = v[0] ;
	for(int i=2 ; i<=n ; i++)
		dp[i] = max(dp[i-1],dp[i-2] + v[i-1]);
	return dp[n] ;
}

int main()
{
	vector<vector<int> > mat ;
	
	int a1[] = {31,83,65,30,15}  ;
	int a2[] = {66,89,0,43,15}  ;
	int n = sizeof(a1)/sizeof(a1[0]) ;
	vector<int> v1(a1,a1+n) ;
	vector<int> v2(a2,a2+n) ;
	mat.push_back(v1) ;
	mat.push_back(v2) ;
	cout<<maximise(mat) ;
	//cout<<maxi<<endl;
}
