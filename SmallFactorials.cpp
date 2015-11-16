#include<iostream>
using namespace std;

void findFactorial(int n)
{
	int arr[499999]={1};
	int i,j,no_of_digits=0;
	int carry = 0;
	if(n==0)
		cout<<1<<endl;
	else{
		for(i=1 ; i<=n ; i++){
			for(j=0 ; j<= no_of_digits ; j++){
				arr[j] = (arr[j] * i) + carry;
				carry = arr[j] / 10;
				arr[j] = arr[j] % 10;
			}
			while(carry){
				no_of_digits++;
				arr[no_of_digits]= carry % 10;
				carry /= 10;
			}
		}
		for(i=no_of_digits ; i>=0 ; i--)
			cout<<arr[i];
		cout<<endl;
		
	}
}

int main()
{
	
	for(int i=1 ; i<=10 ; i++){
		findFactorial(i);
	}
	int tests;
	cin>>tests;
	while(tests--){
		int n;
		cin>>n;
		findFactorial(n);
	}
}
