#include<iostream>
using namespace std ;

int main() {
	int t ;
	cin>>t ;
	while(t--){
		string s ;
		cin>>s ;
		int x ;
		cin>>x ;
		int i;
		int n=0;
		for(i=0 ; i<s.length() ; i++){
			n = n*10 + (s[i]-'0');
			n = n%x  ;
		}
		if(n%x==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

}
