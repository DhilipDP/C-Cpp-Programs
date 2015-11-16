#include<iostream>
using namespace std ;

float sqrt(float n){
	float x = n ;
	float y= 1 ;
	float e = 0.000001;
	while(x - y > e){
		x  = (x+y)/2;
		y = n/x;
		cout<<x<<" "<<y<<endl;
	}
	return x;
}
int main(){
	cout<<sqrt(16)<<endl;
	//cout<<sqrt()
}
