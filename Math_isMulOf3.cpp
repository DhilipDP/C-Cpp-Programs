#include<iostream>
#include<stdlib.h>
using namespace std ;


int isMultipleOf3(int n){
	
	if(n==0)
		return 1 ;
	if(n==1 || n==2)
		return 0;
	if(n < 0)
		n = -n;
	int odd_count=0,even_count=0;
	while(n){
		if(n & 1)
			odd_count++;
		n >>=1 ;
		if(n & 1)
			even_count++;
		n >>= 1;
	}
	return isMultipleOf3(abs(odd_count-even_count));
}
int main(){

	int n;
	for(n=1 ; n<=30 ; n++){
		if(isMultipleOf3(n))
			cout<<n<<endl;
	}	
}

