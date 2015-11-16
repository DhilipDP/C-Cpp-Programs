#include <cmath>
#include <cstdio>
#include<limits.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n ;
    cin>>n ;
    int speed[n];
    int dist[n] ;
    for(int i=0 ; i<n ; i++)
        cin>>speed[i];
    for(int i=0 ; i<n ; i++)
       cin>>dist[i];
    vector<int> res;
    float max = INT_MAX;
    for(int i=0 ; i<n ; i++){
        float ans = dist[i] /speed[i];
        if(ans==max)
            res.push_back(i+1);
        else if(ans < max){
            max = ans;
            res.clear();
            res.push_back(i+1);
        }
        cout<<max<<endl;
    }
    for(vector<int> :: iterator it = res.begin() ; it != res.end() ; it++)
        cout<<*it<<endl;
    return 0;
}

