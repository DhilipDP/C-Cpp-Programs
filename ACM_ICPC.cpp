#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,M ;
    cin>>N>>M ;
    int hash[M+1];
    memset(hash,0,sizeof(hash));
    string s[N] ;
    for(int i=0 ; i<N ; i++){
        cin>>s[i] ; 
    }
  int c=0;
  int temp;
     for(int i=0 ; i<N-1 ; i++){
         for(int j=i+1 ; j<N ; j++){
              temp = 0;
             string s1 = s[i];
             string s2 = s[j];
             for(int k=0 ; k<M ;k++){
                 if(s1[k]=='1' || s2[k]=='1')
                     temp++;
             }
            hash[temp]++;
            if(temp > c)
            	c = temp;
         }
         
     }
    cout<<temp<<"\n"<<hash[temp];
            
        
    return 0;
}

