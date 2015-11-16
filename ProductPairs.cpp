#include<iostream>
#include<map>
using namespace std ;


map<int , int> parent ;
int main()
{
	int n, K ;
	cin>>n >> K ;
	int count = 0;
	parent[1] = 0;
	for(int i=0 ; i<n-1;  i++)
	{
		int s,d ;
		cin>>s>>d ;
		parent[d] = s ;
		int p = d ;
		while( p != 0)
		{
			int q = parent[p] ;
			if( d * q <= K && d*q != 0)
				count++;
			p = q ;
		}
	}
	cout<<count<<endl;
}
