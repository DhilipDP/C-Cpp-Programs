#include<iostream>

using namespace std; 


int areAnagrams(string s1,string s2){
	int count[256]={0};
	int i;
	for( i=0 ; s1[i] && s2[i] ; i++){
		count[s1[i]]++;
		count[s2[i]]--;
	}
	if(s1[i] || s2[i])
		return 0;
	for(i=0 ; i < 256 ; i++){
		if(count[i]!=0)
			return 0;
	}
	return 1 ;
}
int main(){
	string output[] = {"no","yes"};
	cout<<(output[areAnagrams("abcd","dabc")]);
	cout<<(output[areAnagrams("aca","aaca")]);
}
