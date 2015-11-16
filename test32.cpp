#include<iostream>
#include<stdlib.h>
using namespace std ;


void fun(int i)
{
	char c[1000] ;
	itoa(i,c,2);
	cout<<c<<endl;
}

int main()
{
	int n=28 ;
	fun(n);
	fun(1);
	fun(68);

	cout<<endl;
	fun(39); fun(1) ; fun(90);
	
	int a = 123 , b=2 ;
	cout<<(a*b)%100<<" "<<(a+b)%100<<" "<<(a-b)%100<<" "<<(a/b)%100<<" "<<(a%b)%100<<endl;
	cout<<(a&b)%100<<" "<<(a|b)%100<<" "<<(a^b)%100<<" ";//<<ab<<" "<<a%b<<endl;
	cout<<(a<<b)%100<<" "<<(a>>b)%100;//<<" "<<a-b<<" "<<a/b<<" "<<a%b<<endl;
}
