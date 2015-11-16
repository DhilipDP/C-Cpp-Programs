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


struct node{
	ll int val;
	int index;
};
int main() {
	int t;
	s(t);
	while(t--){
		ll int n ;
		sll(n);
		node arr[n];
		map<ll int , ll int> hash;
		int maxi = INT_MIN;
		int mini = INT_MAX;
		FOR(0,n-1){
			ll int v;
			sll(v);
			node n ;
			n.val = v;
			n.index = i; 
			mini = min(mini,val);
			maxi = max(maxi,val);
			hash[]++;
		}
		map<ll int ,int > m;
		ll int num = maxi-mini ;
		ll int c=0;
		
		FOR(0,n-1){
			ll int val = arr[i] ;
			ll int pair1 = arr[i] + num ;
			ll int pair2 = arr[i] - num ;
			if(m[i]==0){
				c += hash[pair1];
			}	
			if(m[val]==0)pair2 >= 0)
			c += hash[pair2];
			//cout<<c<<endl;
		}
		cout<<num<<" "<<c/2<<endl;
	}
	
	return 0 ;
}
