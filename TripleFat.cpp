#include<iostream>

using namespace std ;

int main(){
	int i=1;
	for(i=2 ; i<=3000 ; i+=10){
		if((i*i*i) % 1000 == 888)
			cout<<i<<endl;
	}
}
