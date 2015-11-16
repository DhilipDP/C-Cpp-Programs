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
		
		int n;
		s(n);
		string str ;
		cin>>str;
		string str1 = str.substr(0,n/2);
		string str2 = str.substr(n/2,n/2);
		int ans1 = 0,ans2=0;
		if(str1==str2){
			cout<<str<<endl;
			continue;
		}
		int i;
		for(i=0 ; i<str1.length() ; i++){
			if(str1[i]==str2[i])
				continue ;
			int right =  abs(str1[i] - str2[i]);
			char greater = str1[i] > str2[i] ? str1[i] : str2[i] ;
			char smaller = str1[i] < str2[i] ? str1[i] : str2[i] ;
			int rot =  ('z' - greater) + (smaller - 'a') + 1 ;
			ans1 += min(right,rot);
		}
		
		for(i=0 ; i<str2.length() ; i++){
			if(str1[i]==str2[i])
				continue ;
			int right =  abs(str1[i] - str2[i]);
			char greater = str1[i] > str2[i] ? str1[i] : str2[i] ;
			char smaller = str1[i] < str2[i] ? str1[i] : str2[i] ;
			int rot =  ('z' - greater) + (smaller - 'a') + 1 ;
			ans1 += min(right,rot);
		}
			cout<<ans1<<" "<<ans2<<endl;
			string s1 =  str1+str1 ;
			string s2 = str2 + str2 ;
			if(ans1==ans2){
				if(s1 < s2)
				 (cout<<s2<<endl) ;
				else
				 (cout<<s1<<endl);
			
			}else{
				if(ans1 < ans2 )
				 cout<<s2<<endl ;
				 else
				  cout<<s1<<endl;
			}
				
		
	}
	return 0 ;
}
