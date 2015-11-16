#include<iostream>

using namespace std ;


// binomial 
// C(n,k) = C(n-1,k-1) + C(n-1,k)
//C(n,0) = C(n,n) = 1



int binomial(int n,int k){
	if(k==0 || k==n)
		return 1;
	return binomial(n-1,k-1) + binomial(n-1,k);

}


int dp(int n,int k){

	int C[n+1][k+1];
	int i,j;
	for(i=0 ; i<=n ; i++){
		for(j=0 ; j<=k ; j++)
		{
			if(j==0 || j==i)
				C[i][j] =  1;
			else
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	
	}
	return C[n][k];
}
int main(){
	
	cout<<binomial(5,2)<<endl;
	cout<<dp(5,2)<<endl;

}
