#include<iostream>

using namespace std;

int main()
{
	long int tests;
	cin>>tests;
	while(tests--){
		long int H,P,A;
		bool survived = false;
		cin>>H>>P>>A;
		long int i,damage;
		for( i=1 ,damage=1; ; i++){
			if(survived){			
				H+=A;
				survived=false;
		}	else{
				H-=(P*damage);
				damage++;
				if(H<=0)
					break;
				survived = true;
			}
		}
		cout<<i;
	}
}
