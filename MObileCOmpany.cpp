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
	while(t--){
		int l,m,n ;
		s(l);s(m);s(n);
		int S[n] ;
		int i;
		FOR(0,n-1,i)
			s(S[i]);
		string arr[m];
		for(int i= 0; i<m ; i++)
			cin>>arr[i];
		int sum = 0;
		for(int i=0 ; i<m ; i++){
			
			for(int j=0 ; j<n ; j++){
				if(arr[i][j] == 'Y' && S[j] != 0){
					sum += S[j] ;
					S[j] = 0;					
				}
				 
			}
		}
		cout<<sum<<endl;
	}
	return 0 ;
}
