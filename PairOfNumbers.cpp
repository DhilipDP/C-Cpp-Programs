#include <iostream>
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

vector<vector<int> >dp(1000003, vector<int>(1000003,0) );

int fun(int n,int a,int b,int c)
{
//1	cout<<a<<" "<<b<<endl;
	if(n==a || n==b)
	{	
		return c;
	}
	if( n < a  || n<b)
		return INT_MAX;
	return min(fun(n,a+b,b,c+1),fun(n,a,a+b,c+1));
}



int mini = INT_MAX ;


int find(int a,int b,int c)
{
	if(a==1 && b==1)
	{
		return c;
	}
	if( a < b)
		find(a,b-a,c+1);
	else if(b < a)
		find(a-b,b,c+1);
	else
		return INT_MAX;
}
	
int main() {
	int  n;
	s(n);
	int c =0;
//	cout<<fun(n,1,1,c)<<endl;

	for(int i=1 ; i<=(n/2) ; i++)
	{
		int ct= 0;
		mini = min(mini,find(i,n-i,ct));
	}
	cout<<mini+1<<endl;
//	p(mini);
	return 0 ;
}

