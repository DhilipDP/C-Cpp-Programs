#include<iostream>
using namespace std;
int main(){
	int i,n,j;
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j || i+j==n-1)
				cout<<"n";
			else
				cout<<" ";
		}
		cout<<"\n";
	}
}

	
