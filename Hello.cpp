#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>
#include<utility>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b,it) for( it=a ; it<=b ; ++it)
#define pi pair<int,int> 

using namespace std ;


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
				LCS[i][j] = max(LCS[i][j-1],LCS[i-1][j]);
		}
	}
	return LCS[m][n];
}
int main() {
	string s;
	cin>>s;
	string t ="hello";
	if(length_lcs(s,t,s.length(),5)==5)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0 ;
}
