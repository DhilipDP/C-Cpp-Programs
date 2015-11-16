#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int tests;
	cin>>tests;
	while(tests--){
		long int n;
		cin>>n;
		int val =(int) floor(sqrt(2*n));
		if((val * (val+1))==(2*n))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		
	}
}
	
