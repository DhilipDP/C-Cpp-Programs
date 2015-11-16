#include<iostream>
#include<string.h>
using namespace std ;

int main()
{
	int m[26] ;
	memset(m,0,sizeof m);
	m[0]=1 ; m[1] = 2 ; m[3]=1 ; m['O'-65]=1 ; m['P'-65]=1 ; m['Q'-65]=1; m['R'-65]=1 ;
	int t ; cin>>t ;
	while(t--)
	{
		string s ; cin>>s ;
		int count = 0;
		for(int i=0 ; i<s.length() ; i++)
		{
			count += m[s[i]-65];
		}
		cout<<count<<endl;
	}
	
}
