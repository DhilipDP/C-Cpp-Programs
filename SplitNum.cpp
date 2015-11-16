#include<iostream>

using namespace std;

long long int partition(long long int n)
{ 
	if(n==1 || n==2)
		return 1;
	return (partition(n-1)%1000000007)+ 1;
	
}

int main()
{
	int tests;
	cin>>tests;
	while(tests--){
	
		long long int n;
			cin>>n;
		cout<<partition(n);
	}
	
	
}
