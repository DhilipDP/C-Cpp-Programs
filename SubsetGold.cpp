#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>
#include<utility>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b,it) for( it=a ; it<=b ; ++it)
#define pi pair<int,int> 

using namespace std ;


bool subset(vector<ll int> &arr,ll int n,ll int k){
	
	ll int m[k+1];
	memset(m,0,sizeof(m));
	m[0] = 1;
	for(int i=0 ; i<n ; i++){
		for(int j=k ; j>=arr[i] ; j--)
			m[j] |= m[j-arr[i]];
	}
	return m[k];
}

int main() {
	ll int target ;
	sll(target);
	vector<ll int> arr;
	ll int val;
	ll int sum = 0;
	int i=6;
	while( (cin>>val) != NULL)
		arr.push_back(val),sum+= val;
	ll int n = arr.size();
	if(sum < target)
		cout<<"Oh God! Help me!";
	else{
		while(target <= sum){
			//cout<<"checking: "<<target<<endl;
			if(subset(arr,n,target)){
				cout<<target;
				break;
			}
			target++;
		}
	}
	return 0 ;
}
