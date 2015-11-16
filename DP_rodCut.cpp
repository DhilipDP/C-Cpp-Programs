#include<iostream>
#include<limits.h>
using namespace std ;



int rodCut(int p[],int n){
	
	if(n<=0)
		return 0;
	int maxi = INT_MIN ,q;
	for(int i=0 ; i<n ; i++){
		q =  p[i] + rodCut(p,n-i-1);
		if(q > maxi)
			maxi = q;
	
	}
	return maxi;
}


int cutRodDp(int p[] ,int n){
	int tab[n+1];
	tab[0]=0;
	int maxi ,i,j,q;
	for(i=1 ; i<=n ; i++){
		maxi = INT_MIN ;
		for(j=0 ; j<i ; j++){
			q = p[j] + tab[i-j-1];
			if(q > maxi)
				maxi = q; 
		}
		tab[i] = maxi;
		cout<<tab[i]<<endl;
	}
	return tab[n];
}
int main(){
	
	int p[] = {3,5,8};
	int n = sizeof(p)/sizeof(p[0]);
	cout<<rodCut(p,n)<<endl;
	cout<<cutRodDp(p,n);

}
