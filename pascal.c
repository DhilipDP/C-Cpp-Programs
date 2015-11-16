#include<stdio.h>
#include<stdlib.h>


void generate(int n, int *number_of_rows) {

*number_of_rows = n;
	int line,i,j;
	 int **arr = (int **)malloc(n * sizeof(int *));
	  // DO STUFF HERE
	 for ( line = 0; line <n; line++)
  {
    arr[line] = (int *)malloc((line+2) * sizeof(int));
    // Every line has number of integers equal to line number
    arr[line][0] = line+1;
    for ( i = 1; i <= line+1; i++)
    {
      // First and last values in every row are 1
      if ( line+1== i || i == 1)
           arr[line][i] = 1;
      else // Other values are sum of values just above and left of above
           arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
     // printf("%d\n ", arr[line][i]);
    }
    
    
    //printf("\n");
  }
  for(i=0 ; i<n ; i++)
    {
    	for(j=0 ; j<=n ; j++)
    		printf("%d ",arr[i][j]);
    	printf("\n");
    }
	  	 
	
}


int main()
{
	int n = 5;
	generate(5,&n);
}
