#include<iostream>
#include<algorithm>
using namespace std ;



bool isPalindrome(string s){
	if(s=="")
		return true ;
	string str="";
	int i,len = s.length();
	for(i=0 ; i<len ; i++){
		if(isalpha(s[i]) || isdigit(s[i])) 
		{
			str += tolower(s[i]);
		}
	}
	string temp = str;
	reverse(str.begin(),str.end());
	return (temp==str);
}

int main(){
	string s = "A man, a plan, a canal: Panama";
	cout<<isPalindrome(s);
}
