#include<iostream>
using namespace std ;

int main(){

	long long int l,r;
	cin>>l>>r;
	if(l%2 && r-l >=3)
		cout<<l+1<<" "<<l+2<<" "<<l+3<<endl;
	else if(l%2==0 && r-l>=2)
		cout<<l+0<<" "<<l+1<<" "<<l+2<<endl;
	else
		cout<<"-1"<<endl;
	
}
