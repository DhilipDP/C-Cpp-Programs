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


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

int main() {
	int n ;
	s(n);
	string s ;
	cin>>s;
	int hash[256]={0};
	string ans ="" ;
	for(int i=0 ; i<s.length() ; i++){
		if(hash[s[i]]==0){
			ans += s[i] ;
			hash[s[i]]++;
		}
	}
	cout<<ans;
	return 0 ;
}
