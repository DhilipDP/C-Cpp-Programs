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

int main() {
	int t;
	s(t);
	while(t--){
		int n;
		s(n);
		int arr[n];
		int i;
		FOR(0,n-1,i)
			arr[i]=i;
			int v;
		int hash[n] ;
		memset(hash,-1,sizeof(hash)); 
		FOR(0,n-1,i){
			
			s(v);
			if(v!=-1)
				hash[i] = v;
		}
		int c=0,val = (n* (n-1))/2;
		do{
			int sum = 0;
			bool flag = true;
			FOR(0,n-1,i){
				if(hash[i]!=-1 && hash[i]!=arr[i])
					{
						flag = false;
						break;
					}
				cout<<arr[i]<<" ";
				if(hash[i]==-1 || hash[i] == arr[i])
					sum += arr[i];
				cout<<sum<<endl;
			}
			//cout<<sum
			if(sum == val && flag)
				c++;
		}while(next_permutation(arr,arr+n));
		p(c);
	}
	return 0 ;
}
