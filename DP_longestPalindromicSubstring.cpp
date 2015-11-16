#include<iostream>

using namespace std ;


int lps(string s) {
	
	int n = s.length() ;
	int max_length = 1 ;
	string pal = "" ;
	pal += s[0] ;
	int dp[n][n] ;
	int i,j,k ;
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			dp[i][j] = 0;
	for(i=0 ; i<n ; i++)
		dp[i][i] = 1;
	for(i=0 ; i<n-1 ; i++)
		if(s[i] == s[i+1])
			dp[i][i+1] = 2,max_length=2,pal = s.substr(i,2) ;
	for(k=3 ; k<=n ; k++){
		for(i=0 ; i<=n-k ; i++){
			j = i+k-1 ;
			if(dp[i+1][j-1]!=0 && s[i] == s[j] ){
				dp[i][j] = k;
				if(dp[i][j] > max_length)
					max_length = dp[i][j],pal = s.substr(i,k);
			}
		}
	}
	cout<<pal<<endl;
	return max_length;
}

int main() {
	
	string s = "forgeeksskeegfor";
	cout<<lps(s);
}
