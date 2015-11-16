#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std ;

string  find(int num){
	string ans = "";
	if(num < 10){
		char a[2];
		itoa(num+10,a,10);
		return a ;
	}
	for(int i=9 ; i>=2 ; i--){
		while(num%i==0){
			num /= i;
			ans += (i+'0');
		}
	}
	if(num > 10)
		return "NotPossible";
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	int num = 54 ;
	cout<<find(num);
}
