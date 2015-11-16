#include<iostream>
#include<stdio.h>
using namespace std ;

int arr[10000] ;


unsigned long long  int dp_fib(int n)
{
	
//		cout<<"calculating dp fib of : "<<n<<endl ;
	
		if(arr[n] != 0){
		//	cout<<"already computed !"<<n<<endl;
			return arr[n] ;
		}
		else
			arr[n] = dp_fib(n-1) + dp_fib(n-2);
			return arr[n];
}


int fibo(int n )
{
	int dp[n+1] ;
	dp[0] = dp[1] = 1 ;
	
	for(int i=2 ; i<=n ; i++)
		dp[i] = dp[i-1] + dp[i-2] ;
		
	return dp[n] ;
 }

int fib(int n)

{
//	cout<<"calculating fib of : "<<n<<endl ;
	if( n<2)
		return 1;
	return fib(n-1)	 + fib(n-2) ;
}


int main()
{
	
	arr[0] = arr[1] = 1;

	int n ; cin>>n ;
		
	printf("dp : %lld\n",dp_fib(n));//<<endl;
	cout<<fibo(n);
	cout<<" "<<fib(n);
}
