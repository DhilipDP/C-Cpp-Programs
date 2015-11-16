#include<iostream>
#include<stdlib.h>
using namespace std ;


int compute(int A,int B,int C,int D,int E,int F,int G,int H)
{
	int l1,l2,b1,b2,l3 = 0,b3 = 0,a1,a2,a3=0,area  ;
	l1 = C - A ;
	b1 = D - B ;
	l2 = G - E ;
	b2 = H - F ;
	a1 = l1 * b1 ;
	a2 = l2 * b2 ;
	l3 = min(G,C) - max(A,E) ;
	b3 = min(D,H) - max(B,F) ;
	a3 = l3 * b3 ;
	a1 = l1*b1 ;
	a2 = l2 * b2 ;
	cout<<a3<<endl;
	if(a3 == a1 || a3==a2)
		a3 = 0;
	cout<<a1<< " " <<a2<<" "<<a3<<endl;
	return a1+a2-a3;
}

int main()
{
	cout<<compute(-2,-2,2,2,-1,-1,1,1) ;
	
}
