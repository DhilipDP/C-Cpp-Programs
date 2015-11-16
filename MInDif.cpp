#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<utility>
#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n   ;
    cin>>n;
    int arr[n] ;
    int i;
    for(i=0 ; i<n ; i++)
        cin>>arr[i];
    sort(arr,arr+n);
    map<int , vector<pi> > m ;
    for(i=1 ; i<n ;i++){
        int dif = arr[i]-arr[i-1] ;
        pi k =  mp(arr[i-1],arr[i]);
        m[dif].push_back(k);
    }
    
    map<int,vector<pi> > :: iterator it=m.begin();
    vector<pi> v = it->second;
    vector<pi> :: iterator ite;
    for(ite = v.begin() ; ite!=v.end() ; ite++){
        pi p = *ite;
        cout<<ite->first<<" "<<ite->second<<" ";
    }
    return 0;
}

