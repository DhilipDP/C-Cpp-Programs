#include<iostream>
#include<string.h>

using namespace std ;


int find_decodings(string number){
	int n = number.size();
	int arr[n+1];
//	memset(arr,0,sizeof(arr));
	arr[0]=arr[1]=1 ;
	for(int i=2 ; i<=n ; i++){
		arr[i]=0;
		if(number[i-1]-'0'> 0)
			arr[i] = arr[i-1];
		if(number[i-2]-'0' < 2 || (number[i-1]-'0' < 7 && number[i-2]-'0' <=2))
			arr[i] +=  arr[i-2] ;
	}
	return arr[n];
}
int main(){
	string number = "1234";
	
	cout<<find_decodings(number);
	
}
