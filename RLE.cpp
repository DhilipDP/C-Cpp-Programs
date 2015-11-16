#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std ;

string rle(string s){
	int i;
	string des = "";
	for(i=0 ; s[i] ; i++){
		char c = s[i];
		int count=1;
		while(s[i+1] && c==s[i+1]){
			count++;
			i++;
		}
		char a[100];
		sprintf(a,"%d",count);
		des += a;
		des += "!";
		des += c;
	}
	return des;
}
int main(){
	char c[10001];
	while(fgets(c,10000,stdin)!=NULL){
		string s(c);
		s = s.substr(0,s.size()-1);
	//	cout<<s<<" "<<s.size();
		cout<<rle(s)<<endl;
	}
	return 0;
}
