#include<iostream>
#include<vector>
using namespace std ;

int valid(string s)
{
	int n = s.length();
	if(n == 0)
		return 0;
	vector<vector<int> > dp( n , vector<int>(n,0)) ;
	for(int len = 2 ; len <= n ; len++)
	{
		for(int i=0 ; i<=n-len ; i++)
		{
			int j = i+len-1 ;
			if(len==2){
				dp[i][j] = (s[i]=='(' && s[j]==')')*2 ;
				cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
				continue ; 
			}
			int m1 = 0, m2 = 0 ,m3 = 0;
			m1 = dp[i+1][j] ;
			m2 = dp[i][j-1] ; 
			if(dp[i+1][j-1] != 0)
				m3 = dp[i+1][j-1] + (s[i]=='(' && s[j]==')')*2 ;
			dp[i][j]= max(max(m1,m2),m3);
			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	return dp[0][n-1] ;
}

int main()
{
	cout<<valid("()(())()");
}
