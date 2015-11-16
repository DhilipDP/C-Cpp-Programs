#include<iostream>
using namespace std ;

int main()
{
	for(int i=97 ; i<=122 ; i++)
	cout<<i<<" "<<(char)i<<endl;
	
	int f[100];
	f[0] = 0 ;
	f[1]=1;
	for(int i=2 ; i<100 ; i++){
	
		f[i] = f[i-1] + f[i-2];
		cout<<f[i]<<endl;
	}
}
