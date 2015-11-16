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
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;


vector<string> decode(string message){
	string p;
	string q = message ;
	vector<string> ans ;
	
	for(int j=1 ; j<=2 ; j++){
		cout<<"hello";
	bool flag = false;
	p += j==1 ? '0' : '1' ;
//	p  += ((q[0]-'0') - (p[0]-'0')) + '0' ;ut<<endl<<p<<endl;
	for(int i=1 ; i<q.length() ; i++ ){
		cout<<q[i]<<" ";
		int val;
		if(i==1)
			val = ((q[i-1]-'0') - (p[i-1]-'0')) ;
		else
			val = ((q[i-1]-'0') - (p[i-1]-'0') - (p[i-2]-'0')) ;
		cout<<val<<endl;
		if(val > 1)
		{
			ans.push_back("NONE");
			flag = true ;
			break;
		}
		p += (val + '0') ;
		//cout<<p<<val;
	}
	if(!flag)
	ans.push_back(p);
	p.clear();
	}
	
	return ans;
}

int main() {
	string s = "20";
	vector<string> v = decode(s);
//	cout<<v.size()<<endl;
	vector<string> :: iterator it ;
	for(it= v.begin() ; it!=v.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;

	return 0 ;
}

