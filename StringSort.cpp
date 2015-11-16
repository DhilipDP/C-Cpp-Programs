#include<stdio.h>
#include<string.h>

int main() {
	int n ; 
	char s[10][100] ;
	printf("Number of Srings ?\n") ;
	scanf("%d",&n);
	int i,j ;
	char temp[100];
	for(i=0 ; i<n ; i++)
		scanf("%s",s[i]) ;
	///bubble sort
	for(i=0 ; i<n ; i++){
		for(j= i +1 ; j<n ; j++){
			if(strcmp(s[i],s[j]) > 0){
				strcpy(temp,s[i]) ;
				strcpy(s[i],s[j]);
				strcpy(s[j],temp);
			}
		}
	}
	
	printf("The strings in  ascendinding order\n: ") ;
	for(i=0 ; i<n ; i++)
		printf("%s\n",s[i]);
}
