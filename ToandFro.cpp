#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	while(1){
	int n;
	scanf("%d",&n);
	if(n==0)
		break;
	string str;
	cin>>str;
	int row = (str.length()/n);
	char arr[row][n];
	int i,j,k=0;
	for(i=0 ; i<row ; i++){
		if(i%2==0){
			for(j=0 ;  j<n ; j++)
					arr[i][j]=str[k++];
		}
		else{
				for(j=n-1 ;  j>=0 ; j--)
					arr[i][j]=str[k++];
		}
	}
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<row ; j++)
			printf("%c",arr[j][i]);
	printf("\n");
	}
}
