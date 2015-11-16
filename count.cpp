#include <iostream>
#include<math.h>
using namespace std;


int count_ones(string s)
{
	int c=0;
		for(int i=0 ; i<s.length() ; i++)
			if(s[i]=='1') c++;
		return c;
			
}
int main()
{
	int t ; cin>>t ;
	while(t--)
	{
		string s ; cin>>s ;
		int ones = count_ones(s);
		int zeroes = s.length() - ones ;
		
		int n ;  cin>>n;
		n = ceil( (float)n/2.0 ) ;
		cout<<n<<endl;
		if( n & 1)
			cout<<zeroes<<endl;
		else
			cout<<ones<<endl;
	}
    return 0;
}

