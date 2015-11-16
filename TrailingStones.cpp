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
		int n ;
		s(n);
		int a;
		int b;
		s(a);
		s(b);
		vector<ll int> v;
		v.push_back(0);
		FOR(1,n-1){
			map<int ,int > m;
			vector<ll int> temp = v;
			v.clear() ;
			vector<ll int> :: iterator it ;
			for(it = temp.begin() ; it!=temp.end() ; it++ ){
				int val = *it;
				if(m[val + a]==0){
					v.push_back(val+a);
					m[val+a]=1;
				}
				
				if(m[val + b]==0){
					v.push_back(val+b);
					m[val+b]=1;
				}
			}
		//		vector<ll int> :: iterator it;
	/*	for(it = v.begin() ; it!=v.end() ;it++)
			cout<<*it<<" ";
		cout<<endl;*/
		}
		vector<ll int> :: iterator it;
		for(it = v.begin() ; it!=v.end() ;it++)
			cout<<*it<<" ";
		cout<<endl;
	}
	return 0 ;
}
