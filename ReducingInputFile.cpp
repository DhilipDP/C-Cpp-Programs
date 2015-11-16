#include<iostream>
#include<stdio.h>


using namespace std;

int main(){
	FILE *fp ;
	fp = fopen("file.txt","r");
	char a[100];
	while(fscanf(fp,"%s",a)!=EOF){
		string s(a) ;
		int i ;
		string one="";
		for(i=0  ;s[i] ; i++){
			if(s[i]!=',')
				one += s[i];
			else
				one+=' ';
		}
		cout<<one<<" ";
	}
}
