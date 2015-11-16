#include<iostream>
using namespace std ;

int main()
{
	int i,j;
	string str ;
	cin>>str ;
	int n = str.length() ;
	int m = 0 , s = n-1 ;
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++){
			if(i == j)
				cout<<str[m++] ;
			else if(i + j == n-1)
				cout<<str[s--] ;
			else
				cout<<" ";
		
		}
		cout<<endl;
	}
}
