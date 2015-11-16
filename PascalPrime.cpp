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
	vector<vector<unsigned ll int> > pascal(100, vector<unsigned ll int>(100,0));
	pascal[0][0] = 1;
	for(int i=1 ; i<100 ; i++){
		cout<<i<<":"<<endl;
		pascal[i][0] = 1;
		int j;
		for( j = 1 ; j<=i ; j++){
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
		}
		int hash[10] = {0};
		for(int k=0 ; k<=i ; k++){
			int num = pascal[i][k] ;
			while(num > 0){
				hash[num%10] = 1;
				num/=10;
			}
		}
			bool flag = true;
			for(int j=0 ; j<10 ; j++)
				if(hash[j]==0)
					flag= false;
			if(flag)
				cout<<"prime level: "<<i<<endl;
				
		
		
	}:
	for(int i=0 ; i<=23 ; i++)
	{
	//	if(i==85){
		for(int j=0 ; j<=i ; j++)
			cout<<pascal[i][j]<<" ";
		cout<<endl;
	//	}
	} 
	return 0 ;
}
