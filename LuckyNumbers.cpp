#include<iostream>
using namespace std ;



int lucky(int n){
	
	int c = 2;
	while(c <= n){
		if(n % c==0)
			return 0;
		n = n - n/c;
		c++;
	}
	return 1;
}

int main() {
	for(int n=1 ; n<=100 ; n++){
		if(lucky(n))
			cout<<n<<endl;
	}

}
