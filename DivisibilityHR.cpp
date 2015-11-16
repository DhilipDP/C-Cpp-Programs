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

using namespace std ;


bool isDiv(string a,int n){
	int val =0 ;
	cout<<"checking "<<a<< " " <<n<<endl;
	for(ll int i=0 ; i<a.length() ; i++)
		val = (val + (a[i]-48)%n)%n;//cout<<val<<endl;
	return (val==0);
}

ll int countDivisors(string str,ll int a,ll int b,int p){
	ll int c = 0;
	cout<<str<<endl;
	for(ll int i=0 ;i<str.length() ; i++){
		for(ll int j=i ; j<str.length() ; j++){
			if(isDiv(str.substr(i,j-i+1),p))
				cout<<"yes"<<endl,c++;
		}
		
	}
	return c;
}
int main() {
	cout<<isDiv("318",3);
	int P,Q;
	string str ;
	s(P);
	s(Q);
	cin>>str;
	while(Q--){
		ll int a,b;
		sll(a);
		sll(b);
		ll int count = 0;
		cout<<countDivisors(str.substr(a-1,b-a+1),a,b,P)<<endl;
	}
	return 0 ;
}
