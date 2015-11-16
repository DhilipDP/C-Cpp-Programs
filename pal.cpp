#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	//bool first = false;
	t++;
	for (int j=0 ; j<t ; j++){
	//	cout<<"ho";
	//	getline(cin,s);
		char a[1001];
	//	scanf("[^\n]%s",a);

			fgets(a,1000,stdin);
		//first = true;
		string  s(a);
		string temp="";
		string org="";
		int count=0;
		for(int i=0 ; i<s.length() ; i++){
			if(s[i]==' ' || i==s.length()-1)
			{
				if(temp.length()!=0){
				reverse(temp.begin(),temp.end());
				if(org==temp)
					count++;
				}
				temp="";
				org="";		
			}
			else{
				org+=s[i];
				temp+=s[i];
			}
		}
		if(j!=0)
		cout<<count<<endl;
	}
}
