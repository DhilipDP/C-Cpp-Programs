#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		
		
			int rcenter = m/2 ;
			int ccenter = n/2 ;
		/*	if(rcenter==m-2 || ccenter==n-2)
			{
				cout<<"-1"<<endl;
				continue;
			} */
			for(int i=0 ; i<m ; i++){
				for(int j=0 ; j<n ; j++){
					if(i==rcenter || j==ccenter || (i==0 && j>ccenter) || (j==0 &&  i<rcenter) || (i==m-1 && j<ccenter) || (j==n-1 && i>rcenter))
						cout<<"1 ";
					else
						cout<<"0 ";
					
				}
				cout<<endl;
			}
		
	}
}
