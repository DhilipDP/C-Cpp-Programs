#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;


int b2d(string b){
	reverse(b.begin() , b.end());
	int i = 0 ;
	int s = 0;
	for(i=0 ; i<b.length() ; i++)
		s += (b[i]-'0') * (1<<i);
	return s ; 
}


vector<int> grayCode(int n) {
	vector<int> v ;
	if(n < 2)
	return v;
	vector<string> s ;
	vector<string> :: iterator it ;
	s.push_back("00") ;
	s.push_back("01") ;
	s.push_back("11") ;
	s.push_back("10") ;
	int i ;

	for(i=3 ; i<=n ; i++){
			vector<string> a ;
			vector<string> b ;
		for(it = s.begin() ; it!=s.end() ; it++){
			string st = *it ;
			string str = *it ;
			st.insert(0,"0");
			a.push_back(st);
			str.insert(0,"1");
			b.push_back(str);
		}
		s.clear() ;
		s.reserve(a.size() + b.size());
		s.insert(s.end(),a.begin(),a.end());
		reverse(b.begin(),b.end());
		s.insert(s.end(),b.begin(),b.end());
		
	}
	for(it = s.begin() ; it!=s.end() ; it++)
		v.push_back(b2d(*it));
	return v ;
}
 
int main() {
//	cout<<b2d("10")<<"hello";
	vector<int> v = grayCode(5) ;
	vector<int> :: iterator i ;
	for(i=  v.begin() ; i!=v.end() ; i++)
		cout<<*i <<"  ";
	
}
