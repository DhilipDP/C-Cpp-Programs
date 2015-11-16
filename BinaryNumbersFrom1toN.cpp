#include<queue>
#include<iostream>

using namespace std ;
int main(){
	int n= 5;
	queue<string> q;
//	q.push("0");
	q.push("1");
	while(n--){
		string s = q.front();
		q.pop();
		cout<<s<<endl ;
		string temp = s;
		q.push(s.append("0"));
		q.push(temp.append("1"));
	}
	
}
