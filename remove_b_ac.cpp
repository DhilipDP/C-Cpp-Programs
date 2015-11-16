#include<iostream>
#include<bitset>
using namespace std ;


void remove_b_ac(char str[]){
	int i;
	int index=0 ;
	for(i=0 ; str[i]!='\0';  ){
		//cout<<str[i];
		if(str[i] == 'b')
			i++;
		else if(str[i] == 'a' && str[i+1]!='\0' && str[i+1]=='c')
			i=i+2;
		else
			str[index++]=str[i++];
	}
	str[index]='\0';
}
int  main(){

	char str[] = "badcac";
	remove_b_ac(str);
	cout<<str<<endl;	
}
