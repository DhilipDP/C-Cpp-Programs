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

 ll int second,one,current ;
bool  solve(  ll int a, ll int b, ll int c, ll int &x, ll int &y ){
	second = 0;
	one = 1;
	bool swapped = false ;
	unsigned ll int  i = 0,quo,rem,divs,divd,quo_second,quo_first,gcd;
	if(a < b)  swap(a,b),swapped=true;
	divs = b;
	divd = a;
	while(divs !=0 ){
		gcd = divs;
	//	cout<<divs<<" "<<divd<<" "<<current<<endl;
		quo = divd / divs ;
		rem = divd % divs ;
	//	cout<<quo<<" "<<rem<<endl;
	//	break;
		if(i==0)
			quo_second = quo ;
		if(i==1)
			quo_first = quo;
		divd = divs ;
	    divs = rem ;
	    if(i >= 2){
	//    	cout<<"he"<<" "<<second<<" "<<one<<" "<<quo_second<<endl;
	    	current = (second) - (one*quo_second);
	    	quo_second = quo_first ;
	    	quo_first = quo;
	    	second = one ;
	    	one = current;
		}	
		i++;
	//	cout<<divs<<" "<<divd<<" "<<current<<endl;
	} 
	if(c % gcd != 0)
		return false;
	if(swapped)
		swap(a,b);
//	cout<<quo_second;
	current = (second) - (one*quo_second);
	ll int Y = (c - (a*current))/b;
//	cout<<Y<<" "<<a<<" "<<b<<" "<<c<<endl;
	ll int X = (c-(b*Y))/a;
//	cout<<X<<" "<<Y<<endl;
	x = X + (b/gcd);
	y = Y - (a/gcd);
	return true;
}


int main() {
	int t ;
	s(t) ;
	while(t--){
	 ll int a,b,c ;
		scanf("%lld%lld%lld",&a,&b,&c);
	  ll int x,y ;
		if(solve(a,b,c,x,y))
			printf("%lld %lld\n",x,y);
		else
			printf("They falied!\n");
	}
	return 0 ;
}
