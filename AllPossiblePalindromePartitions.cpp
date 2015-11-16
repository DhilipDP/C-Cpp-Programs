#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;



 	bool **p ;
    
	void dfs(string s,int i,vector<vector<string> > &v,vector<string> &r ){
        if(i==s.size()){
            v.push_back(r) ;
            return ;
        }
        for(int k=i ; k<s.size() ; k++){
            if(p[i][k]){
                r.push_back(s.substr(i,k-i+1)) ;
              //  cout<<"Pushing : "<< s.substr(i,k-i+1)<<endl;
                dfs(s,k+1,v,r);
                r.pop_back();
                //cout<<"Popping"<<endl;
            }
        }
    }
    
	vector<vector<string> > partition(string s) {
        int n = s.length() ;
        vector<vector<string> > v ;
        if(n==0)
            return v ;
        p=new bool *[n];
        int i,j,l ;
        for(i=0 ; i<n ; i++)
            p[i] = new bool[n];
        vector<string> t ;
        for(i=0 ; i<n ; i++){
            p[i][i] = true ;
        }
        for(l=2 ; l<=n ; l++){
            for(i=0 ; i<=n-l ; i++){
                j = i + l - 1 ;
                if(l==2){
                    p[i][j] = (s[i]==s[j]);
                }
                else{
                    p[i][j] = (s[i]==s[j] && p[i+1][j-1]) ;
                }
            }
        }
        dfs(s,0,v,t);
        return v;
    }
    
    
    
 int main() {
 	vector<vector<string> > v = partition("malayalam") ;
	vector<vector<string> > :: iterator it ;
	for(it = v.begin() ; it!=v.end() ; it++){
		vector<string>  s = *it ;
		for(vector<string> :: iterator i = s.begin() ; i!=s.end() ; i++)
			cout<<*i<<" ";
		cout<<endl;
	}
	
	return 0 ; 
}


