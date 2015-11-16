#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;


int maxi(int a , int b){
	return a>b ? a : b;
}
int length_lcs(string x,string y,int m,int n){
	
	if(m==0 || n==0)
		return 0;
		
		if(x[m-1]==y[n-1])
			return length_lcs(x,y,m-1,n-1)+1;
		return maxi(length_lcs(x,y,m,n-1),length_lcs(x,y,m-1,n));
/*	char ar[6101][6101];
	int L[m+1][n+1],i,j;
	for(i=0 ; i<=m ; i++)
		L[i][0]=0;
	for(j=0 ; j<=n ; j++)
		L[0][j]=0;
	for(i=1 ; i<= m ; i++){
		for(j=1 ; j<=n ; j++){
			if(x[i-1]==y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = maxi(L[i][j-1],L[i-1][j]);
		}
	}
	return L[m][n];
*/}



int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		string s,rev;
		cin>>s;
		int k=0;
		for(int i=s.length()-1; i>=0 ; i--)
			rev[k++]=s[i];
		rev[k]='\0';
		int val = length_lcs(s,rev,s.length(),s.length());
		printf("%d\n",s.length()-val);
	}
	
}
