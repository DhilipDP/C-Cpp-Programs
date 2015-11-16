#include<iostream>

using namespace std ;


void demo(int &x,int &y){
	x=2;
	y=3;
}
int main(){

	int a=5,b=6;
	demo(a,b);
	cout<<a<<" "<<b;
}
