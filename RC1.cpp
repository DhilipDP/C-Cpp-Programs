#include<iostream>
#include<vector>
using  namespace std;

int main(){

	int n,i,j ;
	cin>>n ;
	char path[n][n];
	int triangle[n][n];
	memset(triangle,0,sizeof(triangle));
	memset(path,'-',sizeof(path));

	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			cin>>triangle[i][j];

	for(i=n-2 ; i>=0 ; i--){
		for(j=0 ; j<=i ; j++){
			if(triangle[i+1][j] > triangle[i+1][j+1])
				path[i][j]='l';
			else
				path[i][j]='r';
		}
	}
	string ans="";
	j=0;
	for(i=0 ; i<n-1 ; i++){
	//		cout<<"hi";
			ans += path[i][j] ;
			if(path[i][j]=='r')
				j=j+1;
		
	}
	cout<<ans<<endl;
}
