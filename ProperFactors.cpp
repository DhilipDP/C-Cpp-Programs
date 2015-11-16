#include<iostream>
using namespace std ;



int propf(int n){
	int c=0;
	for(int i=2 ; i*i <= n ; i++){
		if(n%i==0)
			i*i==n ? c++ :c+=2;
	}
	return c;

}
int main(){
	int c=0;
	for(int n=10 ; n<=99 ; n++){
		if(propf(n)==6)
			c++;
	}
	cout<<c<<endl;
}
