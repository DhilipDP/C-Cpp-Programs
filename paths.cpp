#include<iostream>
#include<stdio.h>
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
using namespace std;

int find(int *grid,int n,int m){

for (int i = n - 2; i >= 0; i--) {
    grid[n - 1, i] += grid[n - 1, i+1];
    grid[i,n - 1] += grid[i+1, n - 1];
}
 
for (int i = n - 2; i >= 0; i--) {
    for (int j = m - 2; j >= 0; j--) {
        grid[i, j] += max(grid[i + 1, j], grid[i, j + 1]);
    }
}
    return grid[n-1,m-1] - grid[n,m];
}

int main()
{
	int no;
	s(no);
	while(no--){
		int n,m;
		s(n);
		s(m);
		int mat[n][m];
		int i,j;
		for(i=0 ; i<n ; i++)
			for(j=0 ; j<m ; j++)
				s(mat[i][j]);
		int val = mat[0][0];
		cout<<find(*mat, n, m)<<endl;
	}
    
    return 0;
}
