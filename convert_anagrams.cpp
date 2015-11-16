#include<iostream>
using namespace std ;

int main(){
	
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(s.length() % 2)
		{
			cout<<"-1"<<endl;
			continue;
		}
		int hash[256] = {0};
		int n=s.length();

		for(int  i=0 ; i<n/2 ; i++){
			hash[s[i]]++;
		}

			int count =0;
		for(int i=n/2 ; i<n ; i++){
			if(hash[s[i]]==0)
				count++;
			else{
				hash[s[i]]--;
			}
		}
		cout<<count<<endl;
	}
}

