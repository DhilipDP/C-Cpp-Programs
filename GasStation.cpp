#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>

#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;



bool possible(int s,vector<int> &gas,vector<int> &cost){
	int i ;
//	cout<<s<<endl;
	int n=gas.size() ;
	int cap = 0;
	for(i=s ; i<n ; ){
		//cout<<"i: "<<i<<" ";
		if( cap + gas[i] < cost[i] )
			return false ;
		gas[i] -= cost[i];
		cap += cost[i];
		i= (i+1)%n;
		if(i==s)
			return true;
	}
//	return true;
}

int canCompleteCircuit(vector<int> &gas,vector<int> &cost){
	int n = gas.size() ;
	if(n==0)
		return -1;
	int start ;
	int i ;
	for(i=0 ; i<n ; i++){
		start = i;
		if(possible(start,gas,cost))
			return start ;
	}
	return -1;	
}

int main() {
	vector<int> gas ;
	vector<int> cost ;
	gas.push_back(1);
	gas.push_back(2);
//	gas.push_back(6);
	cost.push_back(2);
		cost.push_back(1);
		//cost.push_back(3);
	cout<<canCompleteCircuit(gas,cost) ;
	return 0 ;
}
