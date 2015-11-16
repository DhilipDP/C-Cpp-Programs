#include<iostream>
#include<math.h>

using namespace std ;

bool isPrime(int n){
	if(n==1)
		return false;
	for(int i=2 ; i<=sqrt(n) ; i++)
	{
		if(n % i == 0)
			return false ;
	}
	return true ;
}

int  main(){
	for(int i=1000 ; i<=9999 ; i++){
		int n= i;
		if(isPrime(n/1000) && isPrime(n/100) && isPrime(n/10) && isPrime(n))
			cout<<i<<endl;
	}
}
