
#include<stdio.h>

int findSquares(int n){
	if(n==1)
		return 1;
	return (n*n) + findSquares(n-1);
}
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0)
			return 0;
		printf("%d\n",findSquares(n)); 
	}
}
