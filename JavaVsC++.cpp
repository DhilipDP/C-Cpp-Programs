#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
	string str;
	while(cin>>str){
		char * e ="__";
	//	cout<<"hello";
		int i,c,java;
		bool flag = true,c_set=false,j_set=false;
		for(i=0 ; str[i] ; i++){
			if(str[i]=='_')
			{
				flag = false;
				c_set = true;
			}
			else if(isupper(str[i])){
				flag = false;
				j_set = true;
			}
		}
		if(c_set && j_set || (str[str.length()-1]=='_'))
			printf("Error!\n");
		else if(flag)
			cout<<str<<endl;
		else if(strstr(str.c_str(),e))
			cout<<"Error!\n";
		else if(c_set){
	//		cout<<"hee";
			string s = str;
			string ans ="";
			for(i=0 ; s[i] ; ){
				if(s[i]=='_' && s[i+1]){
				//	toupper(s[i+1]);
					ans += toupper(s[i+1]);
					i += 2;
				}
				else{
					ans  += s[i];
					i++;
				}
			}
			cout<<ans<<endl;
		}
		else if(j_set){
			string s = str;
			string ans ="";
			for(i=0 ; s[i] ;i++){
				if(isupper(str[i])){
					ans+='_';
					ans+=tolower(str[i]);
				}
				else
					ans += str[i];
			}
			cout<<ans<<endl;
		}
		
		
	}
			}

