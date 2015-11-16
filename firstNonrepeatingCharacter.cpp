#include<iostream>
#include<limits.h>
using namespace std ;


struct count{
	int c;
	int index ;
};

char firstNonRepeating(string s){
	count arr[256]={0};
	for(int i=0 ; s[i] ; i++){
		(arr[s[i]].c)++;
		if(arr[s[i]].c==1)
			arr[s[i]].index = i ;
	}
	int result = INT_MAX;
	for(int i=0 ; i<256 ; i++){
		if(arr[s[i]].c==1 && result > arr[s[i]].index )
			result = arr[s[i]].index;
	}
	return s[result] ;
}

int main(){
	
	string str = "keerka";
	cout<<firstNonRepeating(str);
}
