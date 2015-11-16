#include<iostream>
using namespace std ;


//multiplying without using + & * 
int mulby7(int n){
	return ( (n<<3) - n) ;
}

int mulby9(int n){
	return ( (n<<3) + n);
}
int main(){
	int n= 1;
	for(n =  1 ; n<=10 ; n++)
		cout<<mulby7(n)<<endl;
	for(n =  1 ; n<=10 ; n++)
		cout<<mulby9(n)<<endl;
}
