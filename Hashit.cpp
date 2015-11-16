#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;


string hash[101]={""};

int function(string key)
{
	int sum=0;
	for(int i=0 ; key[i] ; i++)
		sum += (int)key[i];
	return (sum) % 101;
}
int main()
{
	int tests;
	cin>>tests;
	while(tests--){
		int ii=0;
		int n1;
		cin>>n1;
		while(n1--){
			string str;
			cin>>str;
			if(str[0]=='A'){
				str = str.substr(4,str.length()-4);
				int index =  function(str);
				if(hash[index]=="" ){
					hash[index]=str;
					ii++;
				}
				else{
					for(int j=1 ; j<= 19 ; j++)
					{
						int ind = (function(str) + (j*j) + (23*j))%101;
						if(hash[ind]==""){
							hash[ind]=str;
							ii++;
							break;
						}
					}
				}
			}
			else{
				str = str.substr(4,str.length()-4);
				int index =  function(str);
				if(hash[index]==str ){
					hash[index]="";
					ii--;
				}
				else{
					for(int j=1 ; j<= 19 ; j++)
					{
						int ind = (19*(function(str) + (j*j) + (23*j)))%101;
						if(hash[ind]==str){
							hash[ind]="";
							ii--;
							break;
						}
					}
				}
			}
		}
		cout<<ii<<endl;
		for(int i=0 ; i<101 ; i++){
			if(hash[i]!="")
				cout<<i<<":"<<hash[i]<<endl;
		}
			
	}
	return 0;
}
