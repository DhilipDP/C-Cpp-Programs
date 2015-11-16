#include<iostream>

using namespace std ;


void compress(char str[]){

	int lower[26]= {0},upper[26]={0},digit[10]={0};

	int i,last_index =0;
	
	for(i=0 ; str[i] ; i++){
		if(islower(str[i]) && lower[str[i]-97]==0){
			str[last_index++] = str[i];
			lower[str[i]-97]=1;
		}
		if(isupper(str[i]) && upper[str[i]-65]==0){
			str[last_index++] = str[i];
			upper[str[i]-65]=1;
		}
		if(isdigit(str[i]) && digit[str[i]]==0){
			str[last_index++] = str[i];
			digit[str[i]]=1;
		}
	}
	str[last_index]='\0';
	cout<<"COmpressed String: "<<str<<endl;
}
int main(){
	
	char str[] ="malayalaz";
	compress(str);
	cout<<str;
}
