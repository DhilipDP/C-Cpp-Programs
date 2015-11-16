#include<iostream>
using namespace std;

int main(){
	int tests;
cin>>tests;
	while(tests--){
		string s;
		getline(cin,s);
		string str;
		getline(cin,str);
		bool plus=false,equal = false;
		for(i=0 ; str[i] ; i++){
			if(isalpha(str[i]))
				break;
			else if(str[i]=='+')
				plus=true;
			else if(str[i]=='=')
				equal = plus;
		}
	}
}
