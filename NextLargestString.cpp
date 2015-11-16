#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  freopen("input.txt","r",stdin);
    freopen("op.txt","w",stdout);
    int t;
    cin>>t;
    int j=1;
    FILE *fp = fopen("testing.txt","w");
    while(t--){
    	
        string s ;
        cin>>s;
        
        if(s.length()==1){
            cout<<"no answer"<<endl;
            continue;
        }
        int d=-1,i;
        for(i=s.length()-2 ; i>=0 ; i--){
            if(s[i] < s[i+1])
                break;
        }
        if(i==-1)
        {
            cout<<"no answer"<<endl;
            continue;
        }
 
        d = i;
       	 //cout<<"d: "<<d<<endl;
        int j=d+1;
        char min = s[d+1];
        for(i=d+2 ; i<s.length() ; i++){
              if(s[i] > s[d] && s[i] < min){
                  j=i;
                  min=s[i];
              }
        }
        swap(s[d],s[j]);
        string temp1="";
        for(int k=0 ; k<=d ; k++)
        	temp1 += s[k];
        
        string temp2 = "";
        for(int k=d+1 ; k<s.length() ; k++)
        	temp2 += s[k];
        sort(temp2.begin(),temp2.end());
 	//	reverse(temp2.begin(),temp2.end());
        
    string ans=temp1+temp2 ;
      cout<<ans<<endl;
    }
    //cout<<j<<endl;
    return 0;
}
