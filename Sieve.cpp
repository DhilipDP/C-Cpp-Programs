#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;
 
int Sieve(int m){
    int arr[m+1] ;
    for(int i=0 ; i<=m ; i++)
    	arr[i] = 1;
    if(m <= 1)
    	return 0;
    arr[0] = arr[1] = 0;
    int i,j;
    for(i=2 ; i<=m ; i++){
        if(arr[i]==1){
            for(j=i+i ; j<=m ; j+=i)
                arr[j] = 0;
        }
    }
    int p=0;
    for(i=2 ; i<=m ; i++)
        if(arr[i]==1)
            p++;
   return p;
 
}
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    cout<<Sieve();
   /* int t ;
    cin>>t ;
    while(t--){
        int n,m ;
        cin>>n ;
        int F[n+1];
        if(n <= 3)
              m = 1;
        else{
        F[0] = F[1] = F[2] = F[3] = 1 ;
        for(int i=4 ; i<=n ; i++)
            F[i] = F[i-1] + F[i-4] ;
         m = F[n] ;
        }
        cout<<m<<endl;
           
    }*/
    return 0;
}
