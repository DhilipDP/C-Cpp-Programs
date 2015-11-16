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

string add(string num){
//	cout<<num<<endl;
	int n= num.length() ;
	int i= n-1 ;
	if(num[i] != '9'){
		int m = num[i] - '0' ;
		num[i] = (m+1) + '0' ;
		return num;
	}
	reverse(num.begin(),num.end());
	i=0;
	while(i < num.length() && num[i]=='9')
		num[i++]='0';
	if(i >= num.length())
		num += '1';
	else{
		int m = num[i]  - '0' ;
		num[i] = (m+1) + '0' ;
	}
	reverse(num.begin(),num.end());
	return num;
}	

int main() {
	
//	cout<<add("1");
	while(true) {
		string num ;
		cin>>num;
		if(num=="-1")
			break;
		if(num.length()==1)
		{	num[0]=='0' ? cout<<"0"<<endl : cout<<"1"<<endl;
			continue ;
		}
		string ans ;
		ans += num[0] ;
		int val = num[0]-'0';
		int i;
		for(i=1 ; i<num.length() ; i++){
			int n = num[i]-'0';
			int t = val + n ;
			if(t < 9){
				ans += (t + '0');
				val = t;
			}
			else{
				int p = t - 9 ;
				ans = add(ans);
				ans += (p + '0') ;
				val = p ; 			
			}
		}
		if(ans[ans.length()-1]=='0')
			cout<<ans.substr(0,ans.length()-1)<<endl;
		else{
	//		cout<<ans<<endl;
			cout<<add(ans.substr(0,ans.length()-1))<<endl;
		}
	}
	
	return 0 ;
}

