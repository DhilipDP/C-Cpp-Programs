#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	string s ;
	cin>>s;
	int Q;
	cin>>Q;
	int n = s.length();
	
	while(Q--){
		long long int a,b;
		cin>>a>>b;
		int i1 = (a%n)-1;
		int i2 = (b%n)-1;
		if(i1==0)
			i1=n-1;
		if(i2==0)
			i2=n-1;
		cout<<i1<<i2;
		if(tolower(s[i1])==tolower(s[i2]))
			printf("Yes\n");
		else
			printf("No\n");
	
	}
}
