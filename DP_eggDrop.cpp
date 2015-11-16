#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std ;



int eggDrop(int n,int k){
	
	int egg[n+1][k+1];
	int i,j,q ;
	for(i=0 ; i<=n ; i++)	
		egg[i][0] = 0,egg[i][1] =1;
	for(i=0 ; i<=k ; i++)
		egg[1][i] = i;
	for(i=2 ; i<=n ; i++){
		for(j=2 ; j<=k ; j++){
			egg[i][j] = INT_MAX;
			for(int x = 1 ; x<=j ; x++){
				q = 1+ max(egg[i-1][x-1],egg[i][j-x]);
				if(q < egg[i][j])
					egg[i][j] = q;
			}
		}
	}
	return egg[n][k];
}
int main(){

	int n=2;
	int k=100;
	cout<<eggDrop(n,k);
	cout<<endl<<ceil( sqrt(2*36)-0.5 ); 

}

