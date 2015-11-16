#include<stdio.h>

int i;
char s[1001];
int max(int a ,int b){
	return a>b ? a : b ;
}
int length()
{
	if(s[i++]=='l')
		return 1 ;
	return max(length(),length())+1;	
}

int main(){
  int tests;
  scanf("%d",&tests);
  while(tests--){
  	scanf("%s",s);
  	i=0;
  	printf("%d\n",length()-1);
  }
}
