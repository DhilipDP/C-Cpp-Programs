#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std ;



void LCS(string x,string y){
	
	int m = x.length();
	int n= y.length();
	int L[m+1][n+1];
	int i,j;
	for(i=0 ; i<=m ; i++){
		for(j=0 ; j<=n ; j++){
			if(i==0 || j==0)
				L[i][j] = 0;
			else if(x[i-1]==y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i][j-1],L[i-1][j]);
		}
	}
	
	for(i=0 ; i<=m ; i++)
	{
		for(j=0 ; j<=n ; j++)
			cout<<L[i][j]<< " " ;
		cout<<endl;
	}
	cout<<"Length of the LCS is: "<<L[m][n];
	cout<<endl<<"LCS is:"<<endl;
	string lcs="";
	i=m;j=n;
	while(i>0 && j>0){
		if(x[i-1] == y[j-1] ){
			lcs += x[i-1];
			i--,j--;
		}
		else if(L[i][j-1] > L[i-1][j])
			j--;
		else	
			i--;	
	}
	reverse(lcs.begin(),lcs.end());
	cout<<lcs;
}


void lcs(string x,string y){
	int m  = x.length() ;
	int n = y.length() ;
	int tab[2][n+1],i,j,ii;
	cout<<endl;
	string ans = "";
	for(i=0 ; i<=m ; i++){
		ii = i&1 ;
		for(j = 0 ; j<=n ; j++){
			if(i==0 || j==0)
				tab[ii][j] = 0;
			else if(x[i-1]==y[j-1])
				ans += x[i-1],tab[ii][j] = tab[1-ii][j-1] + 1;
			else
				tab[ii][j] = max(tab[ii][j-1],tab[1-ii][j]); 
		
		}
	}
	if(m & 1)
	cout<<endl<<tab[1][n];
	else
	cout<<endl<<tab[0][n]<<endl;
}

int main(){
	cout<<INT_MIN;
	string x = "nanv";
	string y = "nijinvinod";
	LCS(x,y);
	lcs(x,y);
	
}
