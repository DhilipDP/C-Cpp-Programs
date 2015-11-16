#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
	
    if(a < b)
        return gcd(b,a);
    if(b==0)
        return a ;
    return gcd(b,a%b);
    
}

bool possible(int arr[],int n){
   for(int i=0 ;i < n ; i++){
            for(int j=i ; j<n ; j++){
            	cout<<i<<" "<<j<<" "<<arr[i]<<" "<<arr[j]<<endl;
                if(gcd(arr[i],arr[j])==1)
                {
                    return true;
                }
            }
    }
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t ;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
       int arr[n];
        for(int i=0 ;i<n ; i++)
            cin>>arr[i];
        if(possible(arr,n))
			cout<<"YES"<<endl;
        else
        	cout<<"No"<<endl;
    }
    return 0;
}

