#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	for (int i=1 ; i<=n ; i++){
		int m;
		string str;
		cin>>m>>str;
		cout<<i<<" "<<str.erase(m-1,1)<<endl;
	}
}
