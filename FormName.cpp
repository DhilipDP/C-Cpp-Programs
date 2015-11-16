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
		int hash[256]={0};
		for(int i=0 ;i <256 ; i++)
			hash[str[i]]++;
		int q;
		s(q);
		while(q--){
			string temp;
			cin>>temp;
			int thash[256] ;	
			for(int i=0 ; i<256 ; i++)
				thash[i] = hash[i];
				bool flag = true;
			for(int i=0 ; i<temp.length() ; i++){
				if(thash[temp[i]]==0){
					flag  = false ;
					break;
				}
				else
					thash[temp[i]]--;
			}
			if(flag)
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
	}
	return 0 ;
}
