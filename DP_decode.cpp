#include<iostream>

using namespace std ;



int numDecodings(string s){
	int m = s.length() ;
	int c[m+1];
	if(m==0)
		return 0;
	c[0] = 1;
	c[1] = 1;
	int i;
	for(i=2 ; i<=m  ; i++){
		c[i] = 0;
		if(s[i-1] > '0')
			c[i] += c[i-1] ;
		if((s[i-2] == '2' && s[i-1] < '7') || s[i-2] == '1' )
			c[i] += c[i-2] ;
	}
	return c[m] ;
}


int main(){
	string dig = "101";
	cout<<numDecodings(dig);
}
