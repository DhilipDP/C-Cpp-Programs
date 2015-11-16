#include<iostream>
#include<stdlib.h>
using namespace std;

void decimal_to_binary(int n,string &s)
{
	if(n <= 1){
		s+=(n+'0');
		return ;
}
	s += (n%2 + '0');
	n /= 2;
	decimal_to_binary(n,s);
}
	
int main(){
//	f
	int t;
	cin>>t;
	while(t--){
		int one=0,zero=0;
		int n;
		cin>>n;
		string a="";
		 decimal_to_binary(n,a);
		for(int i=0 ; i<a.length() ; i++){
			if(a[i]=='1')
				one++;
			else
				zero++;
		}
		if(one==zero)
			cout<<"JUSTICE"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
