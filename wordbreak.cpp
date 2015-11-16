#include<iostream>

using namespace std;
const int num=3;
string dict[num];
bool find(string s){
	cout<<s<<endl;
	for(int i=0 ; i<num ; i++)
		if(s==dict[i]){
			cout<<"true: "<<s<<endl;
			return true;
		}
		return false;
}
 bool wordBreak(string s) {
        int n = s.length();
        if(n==0)
        	return true;
        bool dp[n+1];
        memset(dp,false,sizeof(dp));
        for(int i=1 ; i<=n ; i++){
        	if(dp[i]==false && find(s.substr(0,i)))
        		dp[i]=true;
        	if(dp[i]==true){
        		cout<<i<<endl;
        		if(i==n)
        			return true;
        		int j;
        		for(j=i+1 ; j<=n ; j++){
        			if(dp[j]==false && find(s.substr(i,j-i)))
        				dp[j]=true;
        			if(j==n && dp[j]==true){
        				cout<<j;
        				return true;
        			}
				}
			
			}
        	
		
		}
		return false;
        
        
 }
int main(){
 dict[0] ="aa";
 dict[1] = "aaaa";	
	cout<<wordBreak("aaaaaaa");
}
