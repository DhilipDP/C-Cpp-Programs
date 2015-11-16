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
#define FOR(a,b,it) for( it=a ; it<=b ; ++it)
#define pi pair<int,int> 

using namespace std ;

int main() {
	
	int t;
	s(t);
	while(t--)
	{ 
 		int n,m,i;
 		s(n);
 		s(m);
 		unsigned ll int sum1=0,sum2=0,temp;
		 FOR(0,n-1,i)
		 {
  		sll(temp);
  		sum1+=temp;
 		}
		FOR(0,m-1,i)
 		{
  		sll(temp);
  sum2 += temp;
 }
 if(sum2>sum1)
 	cout<<"BLUE";
 else if(sum2<sum1)
 	cout<<"RED";
 else
 	cout<<"DRAW";
 cout<<endl;
}
return 0;
}
