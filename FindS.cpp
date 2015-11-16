#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	FILE *fp = fopen("myfile.txt","r");
	char a[1000];
	while(fscanf(fp,"%s",a)!=EOF){
		for(int i=0 ; i<strlen(a) ; i++){
			if(a[i]=='s'){
				cout<<a<<endl;
				break;
			}
				
		}
	}
}
