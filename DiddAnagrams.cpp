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


int fact[10] ;
int main() {
	fact[0] = fact[1] = 1 ;
	fact[2] = 2 ;
	fact[3] = 6 ;
	fact[4] = 24 ;
	fact[5] = 120 ;
fact[6] = 720;
fact[7] = 5040;
fact[8] = 40320;
fact[9] = 362880;
fact[10] = 3628800;
	string s ;
	cin>>s ;
	int hash[26] = {0} ;
	for(int i=0 ; i<s.length() ; i++)
		hash[s[i]-97]++;
	int nr = fact[s.length()] ;
	int dr = 1 ;
	for(int i=0 ; i<26 ; i++)
		if(hash[i]!=0)
			dr *=  (fact[hash[i]]);
	cout<<(nr/dr);
	
	return 0 ;
}
