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


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;


int subset(int arr[],int n,int k){
	int i,sum = 0;
	for(i=0 ; i<n ; i++)
		sum += arr[i] ;
	int j,m[k+1];
	memset(m,0,sizeof(m));
	m[0] = 1;
	vector<int> ans ;
	int cur_sum = k;
	for(i=0 ; i<n ; i++){
	//	cout<<i<<" : "<<endl;
		for(j=k ; j>=arr[i] ; j--){
	//		cout<<j<<" ";
			m[j] |= m[j-arr[i]];
	//		cout<<m[j]<<" "<<endl;
			if(j==cur_sum && m[j]==1)
				cout<<j<<" "<<i<<endl,ans.push_back(arr[i]),cur_sum -= arr[i];
		}
	}
	for(vector<int> :: iterator it =ans.begin() ; it!=ans.end(); it++ )
		cout<<*it<<" " ;
	return m[k] ; 
}

int main() {
	int arr[] = {1,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<endl<<subset(arr,n,4)<<endl;
	return 0 ;
}
