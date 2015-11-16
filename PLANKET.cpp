#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	long int b,r;
	cin>>b>>r;
	int val = b+r;
	int sq = (int)sqrt(val);
	for(long int i=1 ; i<=sq ; i++){
		if(val % i == 0){
			long int fac1 = i;
			long int fac2 = val/i;
			long int row,col;
			if(fac1 > fac2){
				row = fac1;
				col = fac2;
			}
			else{
				row = fac2;
				col = fac1; 
			}
			if(((2*col) + ((row-2) * 2))==b ){
				cout<<row<<" "<<col;
				break;
			}
		}
	}
}
