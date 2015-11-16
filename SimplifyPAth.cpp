#include<iostream>
#include<vector>

using namespace std ;


string simplifyPath(string path){
	string ans ="/";
	int i,j;
	int n = path.length() ;
	if(n==0)
		return ans;
	bool home = false ;
	vector<string> stk ;
	string last ="";
	for(i=0 ;i<n ; ){
		if(path[i]=='/'){
			if(i==n-1)
				break;
			string s="" ;
			for(j=i+1 ; j<n && path[j]=='/' ; j++);
			while(j < n && path[j]!='/' && path[j]!='.')
				s += path[j++] ;
			if(home)
				stk.push_back(s) ;
			else if(s=="home")
				home = true,stk.push_back(s);
			last = s;
			i = j;
		}
		else
			i++;
	}
	if(stk.size()==0)
	{	if(last != "")
			ans += last ;
		return ans ;
	}
	vector<string> :: iterator it ;
	for(it = stk.begin() ; it!=stk.end() ; it++){
		string s = *it ; ans += (s + '/') ;
	}
	return ans.substr(0,ans.length()-1);	
}

int main() {
	cout<<simplifyPath("/a/./b/../../c/");
}


