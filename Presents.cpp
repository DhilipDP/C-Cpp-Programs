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


void findBalanced(ll int arr[],ll int n,vector<ll int> &x1,vector<ll int> &x2,int &d){
	ll int sum = 0; 
	int i,j;
	for(i=0 ; i<n ; i++)
		sum += arr[i];
	int ROW,COL ;
	ROW = (sum+1)/2 ;
	COL = n ;
	bool part[ROW+1][COL+1];
	for(i=0 ; i<=COL ; i++)
		part[0][i] = true ;
	for(i=1 ; i<=ROW ; i++)
		part[i][0] = false ;
	for(i=1 ; i<=ROW ; i++){
		for(j=1 ; j<=COL ; j++){
			if(i < arr[j-1])
				part[i][j] = part[i][j-1] ;
			else
				part[i][j] = part[i][j-1] || part[i-arr[j-1]][j-1];
		}
	}
	//table
/*	for(i=0 ; i<=ROW ; i++)
	{
		for(j=0 ; j<=COL ; j++)
			cout<<part[i][j]<<"  ";
		cout<<endl;
	}
	 */
	int s=0;
	int subset[COL];
	int b[COL];
	memset(b,0,sizeof(b));
	int k,l=COL;
	for(k=ROW ; part[k][l]!=1 ; k--);
	int s1=0,s2=0;
	while(k!=0 && l!=0){
		int t ;
		for(t=l ; part[k][t] !=0 ; t--);
		x1.push_back(arr[t]);
		s1 += arr[t] ;
		b[t] =1 ;
		k = k - arr[t];
		l--;
	}
	for(i=0 ; i<n ; i++)
		if(!b[i])
			x2.push_back(arr[i]),s2+=arr[i];
	//cout<<endl;
	d = abs(s1-s2);
	sort(x1.begin(),x1.end());
	sort(x2.begin(),x2.end());
	
}


int findSwaps(vector<ll int> x1,vector<ll int> x2,ll int l1,ll int l2,ll int arr1[],ll int arr2[]){
	sort(x1.begin(),x1.end());
	sort(x2.begin(),x2.end());
	int c=0;
	FOR(0,l1){
		if(arr1[i] != x1[i])
			c++;
	}
	return c;
}

int main() {
	int t;
	s(t);
	while(t--){
		ll int l1;
		sll(l1);
		ll int l2;
		sll(l2);
		ll int arr1[l1],arr2[l2],arr[l1+l2];
		int k=0;
		ll int dif ,s1=0,s2=0;
		FOR(0,l1-1){
			sll(arr1[i]);
			arr[k++] = arr1[i];
			s1 += arr1[i];
		}
		
		FOR(0,l2-1){
			sll(arr2[i]);
			arr[k++]= arr2[i];
			s2 += arr2[i];
		}
		dif = abs(s1-s2);
		sort(arr1,arr1+l1);
		sort(arr2,arr2+l2);
		vector<ll int> x1,x2;
		int d ;
		findBalanced(arr,l1+l2,x1,x2,d);
		if(d==dif){
			cout<<"Lisa:"<<endl;
			FOR(0,l1-1)
				cout<<arr1[i]<<" ";
			cout<<endl<<"Bart:"<<endl;
			FOR(0,l1-1)
				cout<<arr2[i]<<" ";
			cout<<endl<<"0"<<endl;	
			continue;
		}
	/*	vector<ll int> :: iterator it ;
		for(it = x1.begin() ; it!=x1.end() ; it++)
			cout<<*it<<" ";
		cout<<endl;
			for(it = x2.begin() ; it!=x2.end() ; it++)
			cout<<*it<<" ";
		cout<<endl; */
		int swaps = 0;
		if(x1.size()==l1 && x2.size()==l2)
			swaps = findSwaps(x1,x2,l1,l2,arr1,arr2);
		else{
		
			if(x1.size() < l1){
					int i=0;
				while(x1.size() < l1){
					x1.push_back(x2[i]);
					x2.erase(x2.begin()+i);
					i++;
				}
					sort(x1.begin(),x1.end());
		sort(x2.begin(),x2.end());
				swaps = findSwaps(x1,x2,l1,l2,arr1,arr2);
				 
			}
			else 	if(x2.size() < l2){
				int i=0;
				while(x2.size() < l2){
					x2.push_back(x1[i]);
					x1.erase(x1.begin()+i);
					i++;
				}
					sort(x1.begin(),x1.end());
		sort(x2.begin(),x2.end());
				swaps = findSwaps(x1,x2,l1,l2,arr1,arr2);
				 
			}
		}
		sort(x1.begin(),x1.end());
		sort(x2.begin(),x2.end());
		vector<ll int> :: iterator it ;
		cout<<"Lisa:"<<endl;
		for(it = x1.begin() ; it!=x1.end() ; it++)
			cout<<*it<<" ";
		cout<<endl<<"Bart:"<<endl;
			for(it = x2.begin() ; it!=x2.end() ; it++)
			cout<<*it<<" ";
		cout<<endl<<swaps<<endl; 
	}
	return 0 ;
}

