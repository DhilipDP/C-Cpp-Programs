#include<iostream>
#include<math.h>

using namespace std;

int findFactors(int n){
	 int num = sqrt(n);
	 int count = 0;
	for( int i=1 ; i<=num ; i++){
		if(n%i==0)
			count++;
	}
	return count;
	
}

int main(){
	int tests;
	cin>>tests;
	while(tests--){
		int n;
		cin>>n;
		cout<<findFactors(n);
	}
	return 0;
}
