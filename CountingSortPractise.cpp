#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n ;
    cin>>n;
    int arr[n+1];
    int hash[101]={0};
    int i ;
    for(i=0 ; i<n ; i++){
        cin>>arr[i];
        hash[arr[i]]++;
    }
    cout<<"count:"<<endl;
    for(i=0 ; i<=100 ; i++)
          cout<<hash[i]<<" ";
    cout<<endl;
    cout<<"prefix:"<<endl;
    for(i=1 ; i<=100 ; i++)
           hash[i] += hash[i-1] ;  
    for(i=0 ; i<=100 ; i++)
          cout<<hash[i]<<" ";
        cout<<endl;
    int array[n+1] ;
    for(i=0 ; i<n ; i++){
        if(hash[arr[i]]!=0){
            array[hash[arr[i]]]=arr[i] ;
            hash[arr[i]]--;
        }
    }
    cout<<endl;
    for(i=1 ; i<=n ; i++)
           cout<<array[i]<<" ";
    return 0;
}

