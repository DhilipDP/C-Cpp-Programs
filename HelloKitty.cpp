#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	while(1){

	string str,temp;
	int n;
	cin>>str;
	if(str.length()==1 && str[0]=='.')
		break;
	scanf("%d",&n);
	n--;
	temp = str;
	while(n--)
		str+=temp;
	cout<<str<<endl;
	for(int i=1 ; i<temp.length() ; i++){
		char ch = str[0];
		str = str.substr(1,str.length()-1);
		str += ch;
		cout<<str<<endl;
	}
	}
}
