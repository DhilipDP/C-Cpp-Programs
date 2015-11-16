#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
	int c =0;
	FILE *fp = fopen("C:\\Users\\Nandu Vinodan\\Desktop\\input\\i5.txt","w");
	int n=20;
	fputs("20\n",fp);
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<=i ; j++)
		{
			char arr[100];
			int val = rand()%20 + 1 ;
		/*	if(c!=0){
				c=0;
				val = -val;
			}
			else{
			 c=1;
			}*/
			val = -val;
			itoa(val,arr,10);
			fprintf(fp,"%s ",arr);
		}
		fprintf(fp,"\n");
	}
}
