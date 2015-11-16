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
#include<set>

#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;


int lis(int arr[],int n){
	set<int> tab ;
	set<int> :: iterator it ;
	for(int i=0 ; i<n ; i++){
		tab.insert(arr[i]);
		it = tab.find(arr[i]);
		it++;
		if(it !=tab.end())
			tab.erase(it);
	}
	for(it = tab.begin() ; it!=tab.end() ; it++)
		cout<<*it<< " " ;
	cout<<endl ; 
	
	return tab.size() ;
}


int position(int arr[],int key,int n){
	int l =0 ,r =n-1;
	while(r >= l){
		if(r==l)
			return r;
	int mid = (l+r)/2 ;
	if(arr[mid] >= key && mid-1>=l && arr[mid-1]  < key )
		return mid ;
	if(arr[mid] >= key)
		r = mid - 1;
	else
		l = mid +1;
	}
//	return r ;
}


int LIS(int arr[],int n){
	int tab[n];
	tab[0] = arr[0] ;
	int len = 1 ;
	for(int i = 1 ; i<n ; i++){
		if(arr[i] < tab[0])
			tab[0] = arr[i] ;
		else if(arr[i] > tab[len-1])
			tab[len++] = arr[i] ;
		else
			tab[position(arr,arr[i],len)] = arr[i] ;
		for(int i=0 ; i<len ; i++)
			cout<<tab[i]<<" ";
		cout<<endl;
	}
	cout<<"LIS"<<endl;
	for(int i=0 ; i<len ; i++)
		cout<<tab[i]<<" ";
	return len ;	
}

int main() {
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,13, 3, 11, 7, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<lis(arr,n)<<endl;
	
	cout<<LIS(arr,n);
	return 0 ;
}
