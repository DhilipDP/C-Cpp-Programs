#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//#include<unordered_map>
#define ll long long
using namespace std;
#include<map>

//unordered_map<int , int> m;


map<ll int , int>  m;
vector<string> fib; 
string add(string num1,string num2){
	string res= "";
	reverse(num1.begin(),num1.end());
	reverse(num2.begin(),num2.end());
	int len1 = num1.length() ;
	int len2 = num2.length() ;
	int i,carry=0;
	for(i=0 ; i<max(len1,len2) ; i++){
		int d1 = i<=len1 ? num1[i]-'0' : 0;
		int d2 = i<=len2 ? num2[i]-'0' : 0;
		int sum = (d1+d2+carry)%10;
		carry = (d1+d2+carry)/10;
		res +=(sum + '0');
	}
	if(carry!=0)
		res += (carry+'0');
	reverse(res.begin(),res.end());
	return res;
}


string to_string(int n){
	string s;
	if(n==0)
		return "0";
	while(n > 0){
		s += (n%10 + '0');
		n/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
/*

void _fibo(){
		fib.push_back("0");
		fib.push_back("1");
	    m[0]=1;
	    m[1]=1;
	    ll int val=1;
	    ll int i=2;
	    while(val <= 10000000000){
	    	string s = add(fib[i-1],fib[i-2]);
			ll int p = atol(s.c_str());
			m[p] = 1;
			val  = p;
		}
} */

ll int arr[100000];
void _fibo(){
	ll int val =1 ;
	arr[0]=0;arr[1]=1;
	for(int i=2 ; val<=10000000000 ; i++)
	{
	val = arr[i-1] + arr[i-2];	
	arr[i] = val;
	m[val] =1;
	}
	
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  
  	_fibo();
    int t;
    cin>>t;
    while(t--){
        ll int n;
        cin>>n;
  
        if(m[n]==1)
            cout<<"IsFibo"<<endl;
        else
             cout<<"IsNotFibo"<<endl;
        
    }
  //  _fibo() ;
    return 0;
}

