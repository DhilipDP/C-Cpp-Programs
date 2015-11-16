#include<iostream>

using namespace std ;

int main(){
	unsigned long long int sum = 0;
	int n=1000;
	int val=10;
	while(n > 0){
		int dif = val;
		int temp = n;
		sum += n;
		while(dif >= 1){
			n -= dif ;
			sum += n;
			dif--;
		}
		n = temp-100;
		val--;
		cout<<sum<<endl;
	}
	cout<<sum<<endl;
}
