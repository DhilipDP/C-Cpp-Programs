#include<stdio.h>
#include<iostream>
using namespace std ;
int main(){
	
char arr[100];
	FILE *fp = fopen("C:\\Users\\Nandu Vinodan\\Desktop\\Prog.txt","r");
	FILE * fp1 = fopen("write.txt","w");
	char arr[100];
//	fgets(arr,100,fp);
	while((fscanf(fp,"%s",arr)) != EOF)
				{
					char upp[100]={'\0'};
					for(int i=0 ; i < strlen(arr) ; i++){
						if(isalpha(arr[i]))
						upp[i] = arr[i] - 32;
						else
						upp[i] = arr[i];
					}
					fprintf(fp1,"%s\n",upp);
				}
				
		
	
	
	
}
