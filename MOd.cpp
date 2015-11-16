#include<iostream>
using namespace std ;

int mod(int m,int n)
{
	int res = m% n ;
	if(res < 0)
		res += n ;
		return  res ;
}


int main()
{
	int x = -1 ,n=2,d = 20 ;
	int res =1;
	while(n > 0)
	{
		if(n & 2)
			res  = mod(res * x,d);
		x = mod((x * 2),d);
		n = n/2 ; 
	}
	cout<<res<<endl;
}
