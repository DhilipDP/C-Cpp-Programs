#include<iostream>

using namespace std;

int main()
{
	long int tests;
	cin>>tests;
	while(tests--){
		long int H,P,A;
		cin>>H>>P>>A;
		long int current = H;
		long int red = P-A;
		long int time=0;
		while(current > red){
			if((current - red)==A)
				break;
			current -= red;
		
			red += P;
			time+=2;
		}
		cout<<time+1<<endl;
	}
		return 0;
}
