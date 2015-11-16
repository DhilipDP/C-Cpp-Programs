#include<iostream>

using namespace std ;


void longestPalSubstr(char str[]){
	int size = strlen(str);
	int start =0 ,maxlen =1 ;
	int table[size][size] ;
	memset(table,0,sizeof(table));
	int i,k,j;
	for(i=0 ; i<size ; i++)
		table[i][i] = 1 ;
	for(i =0 ; i<size-1 ; i++){
		if(str[i] == str[i+1]){
			table[i][i+1] = 1;
			start = i;
			maxlen = 2;
		}
	}
	for(k = 3 ; k<=size ; k++){
		for(i=0 ; i<= size-k ; i++){
			j = i+k-1;
				if(table[i+1][j-1] && str[i]==str[j]){
					if(k > maxlen){
					maxlen = k;
					start = i;
					}
					table[i][j] = 1 ;
				}
			
		}
	}
	cout<<start<<" "<<maxlen <<endl;
	for(i=start ; i<start+maxlen; i++)
		cout<<str[i]<<" ";
	cout<<endl;
}
int main(){
	char str[]  ="aurline";
	longestPalSubstr(str); 
}
