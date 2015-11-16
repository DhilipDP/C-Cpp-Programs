#include<iostream>
using namespace std ;

int main(){
	string s;
	cin>>s;
	int hash[256]={0};
	int n = s.length();
	for(int i=0 ; i<n  ; i++){
		hash[s[i]]++;
	}
	int odd_count=0,even_count=0;
	for(int i=0 ; i<256 ; i++){
		if( hash[i]%2==1)
			odd_count++;
		else if(hash[i]!=0 && hash[i]%2==0)
			even_count++;
	}
 //cout<<odd_count<<" "<<even_count<<endl;
	bool flag = false;
	if(n%2 && odd_count==1)
	{
		flag = true; 
	}
	else if(n%2==0 && odd_count==0){
		flag = true;
	}
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;


}
