#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

 int hash1[100];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n ,i;
    cin>>n;
    vector<int> arr(n,0);
    cout<<"hi";
    vector<string> s(n,"");
    cout<<"hello";
    for(i=0 ; i<n ; i++){;
        cin>>arr[i];
        cin>>s[i];
        hash1[arr[i]]++;
    }
    for(i=1 ; i<100 ; i++)
        hash1[i] += hash1[i-1];
    string ans[n+1];
    for(i=0 ; i<=n ; i++)
    	ans[i]="-";
   	for(i=n-1 ; i>=n/2 ; i--){
   		ans[hash1[arr[i]]] = s[i];
   		hash1[arr[i]]--;
	}
	for(i=1 ; i<=n ;i++)
		cout<<ans[i]<<" ";
    return 0;
}

