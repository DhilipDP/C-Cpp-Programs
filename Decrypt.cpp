#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
//	cout<<('d'+2 ) % ;
//	cout<<(char)( ) ;
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int key;
		scanf("%d",&key);
		string str,mes;
		cin>>str;
		char ch;
//		mes += (char)((str[0]+key)%26);
//		cout<<mes<<endl;
		if(key<25){
			for(int i=0 ; str[i] ; i++){
				ch = str[i];
				if(ch=='.')
					mes+=" ";
				else if(islower(str[i])){
					ch = ch - 97;
					ch = (ch+key)%26;
					ch = ch + 97;
					mes += ch;
				}
				else{
					ch = ch - 65;
					ch = (ch+key)%26;
					ch = ch + 65;
					
				}
			}
		}
		else{
			for(int i=0 ; str[i] ; i++){
				ch = str[i];
				if(ch=='.')
					mes+=" ";
				else if(islower(str[i])){
					ch = ch - 97;
					ch = (ch+key)%26;
					ch = ch + 65;
					mes += ch;
				}
				else{
					ch = ch - 65;
					ch = (ch+key)%26;
					ch = ch + 97;
					
				}
			}
			
		}
		cout<<mes<<endl;
	}
	return 0;
}
