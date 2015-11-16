#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std ;


int  split(string s, string arr[])
{
	string temp = "";
	int k=0;
	for(int i=0 ; i<s.length() ; i++)
	{
		if(s[i]==' ')
		{
			arr[k++] = temp ;	
			temp= "" ;
		}
		else
			temp += s[i] ;
		
	}
	arr[k++] = temp.substr(0,temp.length()-1) ; 
	return k;
}
int main()
{
	int count = 0;
	char s[1000] , t[1000] ;
	fgets(s,1000,stdin) ;
	fgets(t,1000,stdin) ;
	string s1(s) ;
	string t1(t) ;
	string ss[100] , tt[100] ;
	int l1 = split(s1,ss) ;
	int l2 = split(t1,tt) ;
	for(int i=0 ; i<l1 ; i++)
	{
		for(int j=0;  j<l2 ; j++)
		{
		string tem1 = ss[i] , tem2 = tt[j] ;
			sort(tem1.begin() , tem1.end()) ;
			sort(tem2.begin() , tem2.end()) ;
			if(tem1 == tem2)
			{
				cout<<ss[i]<<" "<<tt[j]<<endl;
				count++;
			}
		}
	}
	cout<<count<<endl;
}
