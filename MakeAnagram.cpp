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
	int t;
	s(t);
	while(t--){
		string s;
		cin>>s;
		int n = s.length() ;
		if(n %2){
			p(-1);
			continue;
		}
		int hash[256]={0};
		for(int i=0 ; i<n/2 ; i++)
			hash[s[i]]++;
		int count =0;
		for(int i=n/2 ; i<n ; i++){
			if(hash[s[i]]==0)
				count++;
			else
				hash[s[i]]--;
		}
		p(count);
	}
	return 0 ;
}

