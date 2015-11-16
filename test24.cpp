#include<iostream>
#include<limits.h>
using namespace std ;

int main()
{
	int n = INT_MAX;
	
	int c=0 ;
	while ( n)
	{
		 n &= (n-1) ;
		 c++;
	}
	cout<<c;

}
