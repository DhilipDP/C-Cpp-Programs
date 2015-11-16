#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,j=0 ;
    cin>>n;
    int arr[n];
    for(i=0 ; i<n ; i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int del = 0,temp=n;
    cout<<temp-del<<endl;
    for(i=0 ; i<n ; ){
        del = 0;
        for(j=i ; j<n && arr[j] == arr[i] ; j++)
            del++;
        cout<<temp-del<<endl;
        if(temp-del==0)
        	break;
        temp -= del;
        i=j;
    }
    return 0;
}

