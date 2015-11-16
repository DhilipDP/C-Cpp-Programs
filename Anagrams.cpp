#include<iostream>
using namespace std ;

int main() {
	int t ;
	cin>>t ;
	while(t--){
		int hash[256] = {0};
		string str1,str2 ;
		cin>>str1>>str2 ;
		int i;
		for(i=0 ; i<str1.length() ; i++)
			hash[str1[i]]++;
		for(i=0 ; i<str2.length() ; i++)
			hash[str2[i]]--;
		int flag = 0 ;
		for(i=0 ; i<256 ; i++){
			if(hash[i]!=0){
				flag=1 ;
				break;
			}
		}
		if(flag==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
				
		
	}
}
