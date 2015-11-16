#include<stdio.h>


//edit distance according to codechef


int mini(int a,int b){
	return a<b ? a : b;
}
int editDistance(int A[],int B[],int m,int n){
		int edit[m][n];
		int i,j;
		for(i=0 ; i<=n ; i++)
			edit[0][i]=i;
		for(i=0 ; i<=m ; i++)
			edit[i][0] = i;
		int left,top,corner ;
		for(i=1 ; i<=m ; i++)
		{
			for(j=1 ; j<=n ; j++){
				left = edit[i][j-1];
				left++;
				top = edit[i-1][j];
				top++;
				corner = edit[i-1][j-1];
				if(A[i-1]!=B[j-1])
					corner++;
				edit[i][j] = mini(corner,mini(top,left));
			}
		}
		return edit[m][n];
}
int main(){

int t;
scanf("%d",&t);
	while(t--){
			int m,n;
	
			int i;
			scanf("%d",&m);
			int A[m];
			for(i=0 ; i<m ; i++)
				scanf("%d",&A[i]);
			scanf("%d",&n);
					
			int B[n];
			for(i=0 ; i<n ; i++)
				scanf("%d",&B[i]);
			printf("%d\n",editDistance(A,B,m,n));
	}

}
