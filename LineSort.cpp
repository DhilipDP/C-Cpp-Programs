#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int main()
{
//	char s[1000] ;
	string str = "";
	int n=3 ;
	while(n--)
	{
		char s[1000];
		fgets(s,1000,stdin);
		string t(s);
		str+= t;
	}
	cout<<str[str.length()-1]<<endl;
	sort(str.begin(),str.end());
	cout<<str<<endl;
}
