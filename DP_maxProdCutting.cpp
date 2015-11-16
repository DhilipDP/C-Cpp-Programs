#include<iostream>
#include<limits.h>
using namespace std ;



int maxProdCutting(int n){
	cout<<n<<endl;
	if(n<=1)
		return 1 ;
	int i ;
	int maxi = INT_MIN ;
	int q =0;
	for(i=1 ; i<n ; i++){
		cout<<i<<" "<<n-i<<endl;
		q = maxProdCutting(n-i)*i;
		if(q > maxi)
			maxi = q ;
	}
	return maxi ;
}


int main(){
	int n = 4 ;
	cout<<maxProdCutting(3);
}
