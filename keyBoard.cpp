#include<iostream>

using namespace std ;

int keyBoard[30];



int find( char c ,string a){
	for(int i=0 ; i<a.length() ; i++)
		if(a[i]==c)
			return i;

}
int main(){

	string key ="qwertyuiopasdfghjkl;zxcvbnm,./";
	string s;
	char c;
	cin>>c;
	cin>>s;
	string ans ="";
	int toggle = c=='L' ? 1 : -1;

	
	for(int i=0 ; i<s.length() ; i++){
		ans += key[find(s[i],key)+toggle];
	
	
	}
	cout<<ans<<endl;	
	
	
}

