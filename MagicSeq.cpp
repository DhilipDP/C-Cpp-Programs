#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>
#include<utility>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)
#define pi pair<int,int> 
#define mod 1000000007

using namespace std ;

int main() {
	int tab[100001]={0};
	tab[1] = 2;
	tab[2] = 3;
	int final = 3;
	int d = 0;
	int t;
	s(t);
	while(t--){
		int n;
		s(n);
		if(n<=2)
 		{
 			cout<<tab[n]%mod<<endl;
 			continue;
 		}
 		FOR(final,n)
 		{
 			 tab[final]=((tab[final-1]%mod)+(tab[final-2]%mod)-d)%mod;
  			d++,final++;
		 }
 		cout<<tab[n]%mod<<endl;
    }
	
	return 0 ;
}
