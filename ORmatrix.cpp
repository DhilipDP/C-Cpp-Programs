#include<stdio.h>
#include<iostream>

using namespace std;


int main(){
	
	int m,n;
	scanf("%d%d",&m,&n);
	int A[m][n],B[m][n];
	int i,j;
	for(i=0 ; i<m ; i++)
		for(j=0 ; j<n ; j++)
			scanf("%d",&A[i][j]),B[i][j]=1;
	
	int count=0;
//	int row[100],col[100];
//	memset(row,0,sizeof(row));
//	memset(col,0,sizeof(col));
	bool one = true;
	for(i=0 ; i<m ; i++){
		for(j=0 ; j<n ; j++){
			if(A[i][j]==0)
			{
		//		row[i]=1;
		//		col[j]=1;
				for(int k=0 ; k<n ; k++)
					if(B[i][k]==1)
						B[i][k]=0,count++;
				for(int k=0 ; k<m ; k++)
					if(B[k][j]==1)
						B[k][j] =0,count++;	
					
			}
			else
				one=true;
		}
	}
	
	for(i=0 ; i<m ; i++){
		for(j=0 ; j<n ; j++){
			if(B[i][j]==1){
				for()
			
			}
		}
	}
	
	if(one && count==(m*n))
		printf("NO");
	else{
		printf("YES\n");
		for(i=0 ; i<m ; i++){
			for(j=0 ; j<n ; j++)
				printf("%d ",B[i][j]);
			printf("\n");
		}
	}
}
