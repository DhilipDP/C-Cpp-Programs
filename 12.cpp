#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int s1=0,s2=0;
        int f=1;
        
        while(n--){
            int val;
            cin>>val;
            if(f)
                s1+=val,f=0;
            else
                s2+=val,f=1;
        }
        if(s1 > s2)
            cout<<"Sahil"<<endl;
        else if(s2 > s1)
          cout<<"Rosesh"<<endl;
           else
            cout<<"Draw"<<endl;
       
    }
    return 0;
}

