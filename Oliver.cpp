#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

int value(char c)
{
	if( c == '$' )
		return 100 ;
	char ch = tolower(c) ;
	return (int)ch-96 ;
}
int solve(string s)
{
		int sum = 100 ; char pre='$' , noted_char;
		
		
		
		for(int i=1 ; i<s.length() ; i++)
		{
		//	s[i] = tolower(s[i]) ;
			sum += value(s[i]) ;
			if( pre == '$'){
				noted_char = s[i];
				s[i]  = '$' ;
				i++;
				while( i < s.length() && s[i]!= '$')
					sum += value(s[i]) , i++;
			//	cout<<sum<<endl;
				if(s[i]=='$')
				{
					sum  += value(s[i-1]) + 100 ;
			
					if(noted_char != s[i-1])
						return sum ;
							s[i-1] = '$' ;
					i-=2;
					while( i >=0 && s[i] != '$')
						sum += value(s[i])	, i--;
					if(s[i] == '$'){
						sum += 100;
						if(s[i+1]=='$')
							return sum ;
					}
					
				}
				
			}
			pre = s[i];
		}
}

int main() {
	int t ;
	s(t) ;
	while(t--)
	{
		string s ;
		cin>>s ;
		cout<<solve(s)<<endl ;
	}
	return 0;
}
