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


int shift(string s){
	int n = s.length();
	int mini = atoi(s.c_str()) ;
	while(n--){
		string temp = s;
		string ans = s.substr(1,s.length()-1);
		ans += temp[0];
		int val = atoi(ans.c_str());
		if(val < mini)
			mini = val;
	}
	return mini;
}

int add(string s){
	int t=10;
	int mini = atoi(s.c_str()) ;
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	while(t--){
		for(int i=0 ; i<s.length() ; i++)
			s[i] = (arr[s[i]-'0']) + '0';
		int val = atoi(s.c_str());
		if(val < mini)
			mini = val;
		cout<<s<<endl;
	}
	return mini;
}


int main() {
	int n ;
	s(n);
	string s;
	cin>>s;
	int min1 = shift(s);
//	cout<<min1<<endl;
	int min2 = add(s);
//	cout<<min2<<endl;
	int ans = min(min1,min2);
//	cout<<ans;
	char arr[700];
	itoa(ans,arr,10);
	string a(arr);
	while(a.length() < n)
		a = "0" + a;
	cout<<a;
	return 0 ;
}
