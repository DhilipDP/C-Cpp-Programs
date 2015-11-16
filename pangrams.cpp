#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std ;

int main(){

	char a[1000];
	fgets(a,1000,stdin);
	string s(a);
	int hash[100]={0};
	int len = s.length();
	for(int i=0 ; i<len ; i++){
		if(s[i]!=' '){
			char t = toupper(s[i]);
			hash[t]++;
		}
	}
	bool flag = true;
	for(int i=65 ; i<=90 ; i++){
		if(hash[i]==0){
			flag = false;
			break;
		
		}
	
	}
	if(flag)
		cout<<"pangram"<<endl;
	else
		cout<<"not pangram"<<endl;

}
