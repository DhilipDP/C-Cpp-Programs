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



int add(string s){
	cout<<s<<endl;
	int n = s.length() ;
	if(n==1)
		return s[0]-'0' ;
	int sum = 0;
	for(ll int i=0 ; i<n ; i++)
		sum += (s[i]-'0');
	cout<<sum<<endl;
	char t[100000]={'\0'};
	cout<<"ke"<<t<<" "<<endl;
	sprintf(t,"%s",sum);
	cout<<t;
	add(t);
	
}


int main() {
	int t;
	s(t);
	while(t){
		string s ;
		cin>>s;
		cout<<add(s);
		
	}
	return 0 ;
}
