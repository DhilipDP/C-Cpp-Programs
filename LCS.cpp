#include<iostream>
using namespace std;


int maxi(int a,int b)
{
	return a>b ? a : b;
}
int length_lcs(string s1,string s2,int m,int n)
{
	int LCS[m+1][n+1];
	for(int i=0 ; i<=m ; i++){
		for(int j=0 ; j<=n ; j++){
			if(i==0 || j==0)
				LCS[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				LCS[i][j] = LCS[i-1][j-1] + 1;
			else
				LCS[i][j] = maxi(LCS[i][j-1],LCS[i-1][j]);
		}
	}
	return LCS[m][n];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<		length_lcs(s1,s2,s1.length(),s2.length());
}

