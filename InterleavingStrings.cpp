#include<iostream>
using namespace std ;




   bool isInterleave(string s1, string s2, string s3) {
      
     /*   if(lcs(s1,s3)==s1.length() && lcs(s2,s3)==s2.length() && s1.length() + s2.length()==s3.length())
        	return true ;
        return false; */
        int m = s1.length();
        int n = s2.length();
        int i,j;
		bool dp[m+1][n+1];
		memset(dp,false,sizeof(dp));
		if(s3.length()!= (s2.length()+s1.length()))
			return false ;
		for(i=0 ; i<=m ; i++){
			for(j=0 ; j<=n ; j++){
				if(i==0 && j==0)
					dp[i][j]=true;
				else if(i==0 && s2[j-1]==s3[j-1])
					dp[i][j] = dp[i][j-1];
				else if(j==0 && s1[i-1]==s3[i-1])
					dp[i][j] = dp[i-1][j];
				else if(s3[i+j-1]==s1[i-1] && s3[i+j-1]!=s2[j-1])
					dp[i][j] = dp[i-1][j];
				else if(s3[i+j-1]==s2[j-1] && s3[i+j-1]!=s1[i-1])
					dp[i][j] = dp[i][j-1];
				else if(s3[i+j-1]==s1[i-1] && s3[i+j-1]==s2[j-1])
					dp[i][j] = dp[i-1][j] || dp[i][j-1];			
			}
		}
		return dp[m][n];
	}

int main(){
	//cout<<lcs("a","aa");
	string a ="aabcc";
	string b ="dbbca";
	string c = "aadbbcbcac";
	string x="a";
	string y="";
	string z="aa";
//	cout<<lcs(a,c)<<" "<<lcs(b,c);
	cout<<isInterleave(a,b,c);
}
