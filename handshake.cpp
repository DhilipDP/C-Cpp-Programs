#include<iostream>
using namespace std;


int find(int n){
	if(n==0 || n==2)
		return 1;
	if(n%2)
		return 0;
	if(n==4)
		return 2;
	int r;
	for(int i=0 ; i<n ; i++)
		r+= (find(i)*find(n-2-i));
	return r;
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<find(n)<<endl;
	}
}
