#include<iostream>

using namespace std ;


int no_consecutive_ones(int n){

	int a[n+1];
	int b[n+1];
	a[1] = b[1] = 1 ;
	for(int i=2 ; i<=n ; i++)
		a[i] = a[i-1] + b[i-1],b[i] = a[i-1];
	return a[n] + b[n];
}


int main(){
	
	int n = 3 ;
	cout<<endl<<no_consecutive_ones(n);
}
