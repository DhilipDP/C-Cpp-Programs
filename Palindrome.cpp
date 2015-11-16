#include<stdio.h>
#include<string.h>

int main() {
	char str[100] ;
	printf("Enter a string: \n") ;
	scanf("%s",str);
	int len = strlen(str);	
	char rev[100] ;
	int i=len-1,j=0 ;
	for( ; i>=0 ; i--,j++)
		rev[j]  = str[i] ;
	rev[j] = '\0' ;
	printf("The reversed string is %s \n",rev);
	int flag = 0 ;
	for(i=0 ; i<len ; i++){
		if(str[i] != rev[i]){
			flag = 1 ;
			break;
		}
	}
	if(flag==0)
		printf("Palindrome") ;
	else
		printf("Not a palindrome");

	if(strcmp(str,rev)==0)
		printf("Palindrome") ;
	else
		printf("Not a palindrome");
}
