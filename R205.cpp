#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
using  namespace std;

int main(){

	int n,i,j ;
	cin>>n ;
	char path[n][n];
	int mat[n][n];
	memset(mat,0,sizeof(mat));
	memset(path,'-',sizeof(path));
	for(i=0;i<n;i++){
		cout<<"Enter "<<i+1<<" integer(s) :"<<endl;
		for(j=0;j<=i;j++)
			cin>>mat[i][j];
	}
	
	for(i=n-2 ; i>=0 ; i--){
		for(j=0 ; j<=i ; j++){
			//cout<<i<<" "<<j<<":";
			if(mat[i+1][j] > mat[i+1][j+1] ){
				mat[i][j]  += mat[i+1][j]; 
				path[i][j] = '0';
			}
			else{
				mat[i][j] += mat[i+1][j+1];
				path[i][j] = '1';
			}
			//cout<<path[i][j]<<" "<<mat[i][j]<<endl;
			
		}
	}
	string ans="";
	j=0;

	for(i=0 ; i<n-1 ; i++){
			ans += path[i][j] ;
			if(path[i][j]=='1')
				j=j+1;
		
	}
	cout<<ans<<endl;
	}


