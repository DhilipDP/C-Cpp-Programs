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


void find_min(string s,string mini){
	
}
int main() {
	int t;
	s(t);
	while(t--){
		string s ;
		cin>>s;
		sort(s.begin(),s.end());
		string temp ;
		char c = s[0];
		temp += c;
		for(int i=1 ; i<s.length() ; i++)
		{
			if(s[i]!=c){
				c = s[i] ;
				temp += c;
			}
			
		}
	cout<<temp<<endl;
	}
	return 0 ;
}
