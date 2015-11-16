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
 
 int gcd(int a,int b){
 	//cout<<a<<" " <<b;
	if(a<b)
		return gcd(b,a);
	if(b==0)
		return a;
	return gcd(b,a%b);
}

 
 
int findModulus(int a,string b){
	if(a==0)
		return atoi(b.c_str());
	int m = b[0]-'0';
	
	int i=0,d;
	while(b[i]){
		d = m % a;
	//	cout<<"d: "<<d<<end
		if(b[i+1])
			m = (10*d) + (b[i+1]-'0');
		i++;
	//	cout<<d<<endl;
	}
	return d;
}

int calc_gcd(int a,int b){
	a = min(a,b);
	b = max(a,b);
//	string s;
	char ar[100] ;
	itoa(b,ar,10);
	string st(ar);
	//cout<<st<<" ";
	return gcd(a,findModulus(a,st));
}

 

 
int gcd(int arr[],int l,int r,int n,map<pi , int> &m){
 
	int res = 0;
	for(int i=1 ; i<=n ; i++){
	//	cout<<res<<" "<<arr[i]<<endl;
		if(i==l)
			i = r;
		else{
			pi p = make_pair(res,arr[i]);
			if(m[p]==0){
				res = calc_gcd(res,arr[i]);
				m[p] = res;
			}
			else{
				res = m[p];
			}
		}
	}
	return res;
	
}
int main() {
	int t;
	s(t);
	while(t--){
		int n,q;
		s(n);
		s(q);
		map<pi , int> m;
		int arr[n+1];
		FOR(1,n)
			s(arr[i]);
		FOR(1,q){
			int l,r;
			s(l);
			s(r);
			p(gcd(arr,l,r,n,m));
		}
			
	}
	return 0 ;
} 
