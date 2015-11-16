#include<iostream>
#include<algorithm>
using namespace std ;


void  convertToTitle(int n,string &ans){
	if(n <= 26){
		ans += (n + 64) ;
		return ;
	}
	int val = n%26 ;
	int quo = n/26;
	if(val==0)
		ans += 'Z' , quo--;
	else
	    ans += (val + 64);
   convertToTitle(quo,ans) ;
}

int main(){

	string ans = "" ;
	convertToTitle(i,ans);
	reverse(ans.begin() ,ans.end());
	cout<<ans<<endl;

}
