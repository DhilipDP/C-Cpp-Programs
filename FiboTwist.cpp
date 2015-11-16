#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define sll(a) scanf("%lld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;


ll int fibo(ll  int n,ll int  m,ll int * tab){
//	cout<<"n : "<<n<<" "<<tab[n] <<endl;
	if(tab[n]==-1){
//		cout<<"hello";
		if(n <= 1)
			tab[n] = n%m;
		else
			tab[n] = (fibo(n-1,m,tab)%m + fibo(n-2,m,tab)%m + (n-1)%m)%m;
	}
	return tab[n];
}


ll int fib(ll int n,ll int m,ll int * tab){
	int arr[1];
}

int main() {
	int arr[10000000];
	int t ;
	s(t);
	while(t--){
		ll int n,m ;
		sll(n);;
		sll(m);
		ll int tab[n+1];
		memset(tab,-1,sizeof(tab));
		printf("%lld\n",fibo(n,m,tab));
	}
	return 0 ;
}


