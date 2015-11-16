#include<iostream>

using namespace std ;


void longestPalSubstr(char str[]){
	int i,j;
	int start =0 ;
	int maxlen = 1 ;
	
	int low;
	int high;
	int len = strlen(str);
	for(i=1 ; i<strlen(str) ; i++){
		low = i-1;
		high = i;
		while(low >=0 && high < len && str[low]==str[high]){
			if(high - low + 1 > maxlen){
				maxlen = high - low + 1 ;
				start = low ;
				maxlen = high - low + 1;
			}
			low--;
			high++;
		}	
	low = i-1 ;
		high = i+1 ;
		while(low >=0 && high < len && str[low] == str[high]){
						if(high - low + 1 > maxlen){
				maxlen = high - low + 1 ;
				start = low ;
				maxlen = high - low + 1;
			}
			low--;
			high++;
			
		} 
	}
	for(i=start ; i<start+maxlen; i++)
		cout<<str[i]<<" ";
	cout<<endl;	
}

int main(){
	char str[]  ="naandnaan";
	longestPalSubstr(str);}
