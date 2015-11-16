#include<iostream>
using namespace std ;

int main()
{
	int n;
	cin>>n;
	string s = "1";
	
	while(n--){
		cout<<s<<endl;
		string str="";
		for(int i=0 ; i<s.length() ; )
		{
			char c = s[i] ;
			int cnt = 0;
			while(i< s.length() && s[i] == c)
				cnt++,i++;
		
			str += (cnt+'0');
			str += c;
		}
	//	cout<<str<<endl;
		s = str;
	}
}
