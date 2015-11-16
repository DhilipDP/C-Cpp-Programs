#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct node{
    int st ;
    int ft ;
};

bool comp(const node &a , const node &b)
    {
    return a.ft < b.ft ;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n ;
    cin>>n ;
    node arr[n] ;
    for(int i=0 ; i<n  ; i++)
    {
        cin>>arr[i].st>>arr[i].ft ;
        
    }
    sort(arr,arr+n,comp) ;
    for(int i=0 ; i<n  ; i++)
    {
      //  cin>>arr[i].st>>arr[i].ft ;
        cout<<arr[i].st<<" "<<arr[i].ft<<endl;
    }
	int count = 1;
	int pre = arr[0].ft ;
    for(int i=1 ; i<n ; i++)
	{
        if(arr[i].st >= pre){
               count++;
               pre = arr[i].ft ;
        }
    }
    cout<<count<<endl;
    return 0;
}

