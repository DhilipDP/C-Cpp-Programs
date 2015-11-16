#include<stdio.h>
#include<string.h>
int st[10000] ;
int top = -1 ;

void push(int i)
{
	st[++top] = i;
} 

int empty()
{
	return (top==-1) ;
}


int pop()
{
	return st[top--] ;
}

int main()
{
	int s,i ,k=0;
	char str[1000] ;
	char temp[strlen(str)] , res[strlen(str)];
	scanf("%s",str) ;
	//printf("hi") ;
	for( s=0 ; s<strlen(str) && str[s]==')' ; s++)
		temp[s] = '0' ;

	for( i=s ; i<strlen(str); i++){
		if(str[i]=='(')
				push(i) ,temp[i] = '1';
		else if(str[i]==')'){
			if(empty())
				temp[i]='0';
			else{
				pop() ;
				temp [i]= '1' ; 
			}
			
		}
		else
			temp [i]='1' ;
	//	printf("%c",temp[i]);
	}
	while(!empty())
		{
			temp[pop()] = '0'  ;
		}
	for( i=0 ; i<strlen(str) ; i++)
		if(temp[i]=='1')
			res[k++]= str[i] ;
		res[k] = '\0' ;
	printf("%s",res);
}	
