#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<stdio.h>
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
using namespace std;

void printAllPathsUtil(int *mat, int i, int j, int m, int n, int *path, int pi,int val,int &min,int sum)
{
//	cout<<i<<" "<<j<<endl;
    if (i == m - 1)
    {
        for (int k = j; k < n; k++)
            path[pi + k - j] = *((mat + i*n) + k);
        int diff = val;
        for (int l = 1; l < pi + n - j; l++)
            diff -= path[l];
            
        if(diff > min)
        	min = diff;
        return;
    }
    if (j == n - 1)
    {
        for (int k = i; k < m; k++)
            path[pi + k - i] = *((mat + k*n) + j);
        int diff = val;
        for (int l = 1; l < pi + m - i; l++)
            diff -= path[l];
        
        if(diff > min)
        	min = diff;
        return;
    }
 
    
    path[pi] = *((mat + i*n) + j);
 /*	sum += path[pi];
 	if(sum - val < 0 ){
 		return ;
 	} */
    
    //if(*((mat + (i+1)*n) + j) < *((mat + i*n) + j+1))
		printAllPathsUtil(mat, i+1, j, m, n, path, pi + 1,val,min,sum);
 
 	//else
   
     printAllPathsUtil(mat, i, j+1, m, n, path, pi + 1,val,min,sum);
 }
 
void printAllPaths(int *mat, int m, int n,int val)
{
    int *path = new int[m+n];
    int min = INT_MIN;
    int sum = 0;
    printAllPathsUtil(mat, 0, 0, m, n, path, 0,val,min,sum);
    if(min < 0)
    	printf("-1\n");
    else
    	p(min);
}


int maxValue(int *field,int r,int c ) {
  
    int maxValues[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 && j == 0) {
                maxValues[i][j]= *((field+ i*c) + j);
            } else if (i == 0) {
                maxValues[i][j] =  maxValues[i][j-1] + *((field+ i*c) + j);
            } else if (j == 0) {
                 maxValues[i][j] =  maxValues[i-1][j] +  *((field+ i*c) + j);
            } else {
                maxValues[i][j] = max( maxValues[i][j-1],  maxValues[i-1][j]) +  *((field+ i*c) + j);
            }
        }
    }
    return maxValues[r-1][c-1];
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
	//	printAllPaths(*mat, n, m,val);
		int v = maxValue(*mat,n,m);
		if(v < 0)
			printf("-1\n");
		else
			p(v);
	}
    
    return 0;
}

