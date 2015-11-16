#include<iostream>

using namespace std ;

int main(){
	int  n = 712452;
	int sum = 0;
	for(int i=n-1 ; i>=2 ; i--){
		sum = 0;
		if(n % i==0 ){
			cout<<i<<endl;
			for(int j=2 ; j*j <= n ; j++){
				if(i%j==0){
					sum += i;
					if(i/j != j)
					sum += (i/j);
				}
			}
			cout<<i<<" "<<sum<<endl;
			if(sum < i)
				cout<<i;
		}
		
	}
}
