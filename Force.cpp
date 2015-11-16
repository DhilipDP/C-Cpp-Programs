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
#define FOR(a,b) for(int i=a ; i<=b ; ++i)
#define pi pair<int,int> 

using namespace std ;


struct node{
	ll int force;
	ll int energy;
	string s;

};



int comp(const void * a,const void * b)
{
	node *p1 = (node *)a;
	node *p2 = (node *)b;
	return (p1->force - p2->force);
}
int main() {
	int t;
	s(t);
	while(t--){
		ll int n;
		sll(n);
		node arr[n];
		FOR(0,n-1)
			sll(arr[i].force);
		FOR(0,n-1)
			sll(arr[i].energy);
		string str[n];
		FOR(0,n-1)
			cin>>arr[i].s;
		ll int sum;
		sll(sum);
	//	cout<<sum<<endl;
		qsort(arr,n,sizeof(node),comp);
		int low = 0,high=n-1;
		ll int max_en = INT_MIN ;
		string s1,s2;
		while(low < high){
		//	cout<<"hi";
			ll int val = arr[low].force + arr[high].force ;
		//	cout<<val;
			if(val < sum)
				low ++;
			else if(val > sum)
				high--;
			else{
				int h=high ;
				while(arr[h].force==arr[high].force){
				if(arr[low].energy + arr[h].energy == max_en){
					if(arr[h].s < s1){
						s1 = arr[h].s;
						s2 = arr[low].s;
					}
					else if(arr[h].s==s1 && arr[low].s < s2){
						s1 = arr[h].s;
						s2 = arr[low].s;
					
					}
					
				}
				else if(arr[low].energy + arr[h].energy > max_en){
					max_en = arr[low].energy + arr[h].energy ;
					s1 = arr[h].s;
					s2 = arr[low].s;
				}
					h--;
				}
				low++;		
				cout<<low<<" "<<high<<max_en<<" "<<endl;
			}
		}
		cout<<s1<<" "<<s2<<endl<<max_en<<endl;
	}
	return 0 ;
}
