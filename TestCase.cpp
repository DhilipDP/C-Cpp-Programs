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


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

int main() {
	int n;
	s(n);
	int arr[n+1];
	FOR(1,n)
		s(arr[i]);
	vector<int> num ;
	vector<int> ans ;
	ans.push_back(n);
	num.push_back(n);
	for(int i=n ; i>=1 ; i-- ){
	//	num = ans;
		cout<<i<<" : ";
		for(vector<int> :: iterator it = ans.begin() ; it!=ans.end() ; it++){
		int val = *it-i;
			if(arr[i] > 0 && val==arr[i]){
				num.push_back(*it-val-1);
			//	cout<<"Pushed " <<n-val-1<<endl;
			}
		}
		ans = num;
	}
	sort(ans.begin(),ans.end());
		for(vector<int> :: iterator it = ans.begin() ; it!=ans.end() ; it++){
			cout<<*it<<endl;
		}
	return 0 ;
}
