#include<stdio.h>

int main(){

	FILE *fp1,*fp2;
	fp1 = fopen("sender.txt","r");
	fp2 = fopen("receiver.txt","w");
	
	char recv[100] = {'\0'};
	while((fgets(recv,100,fp1))!=NULL){
	
		fprintf(fp2,"%s",recv);
	}
	//<<"Transefered";

}
