#include <iostream>
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

ll int find_left_distance(int x,int y,int &level1,int &level2)
{
	int l,r;
	int k=2;
	int num=1;
	while( num < x){
		num += (pow(2,k)-1);
		k++;
	}
	l=k-1;
	 k=2;
    num=1;
	while( num < y){
		num += (pow(2,k)-1);
		k++;
	}
	r = k-1;
	level1 = l;
	level2 = r;
//	cout<<l<<" "<<r<<endl;
	return r-l;
	
}

ll int find_cur_distance(int y,int level)
{
	int v = 1;
	int no=0;
	level--;
	while(level--){
		no += pow(2,v)-1;
		v++;
	}
	no++;
	v=0;
	int num = no;
	int k=1;
	while( num < y){
		num += (no + pow(2,k));
		v++;
		k++;
	}
	return v;	 
}


int main() {
	int t ;
	s(t);
	while(t--){
		int x,y;
		s(x);
		s(y);
		ll int dist =0;
		int level1 =0,level2=0;
		dist += find_left_distance(x,y,level1,level2);
		cout<<level1<<" "<<level2<<" "<<dist<<endl;
		dist += find_cur_distance(x,level1);
		cout<<dist<<endl;;
		dist += find_cur_distance(y,level2);

		printf("%d\n",dist);
	}
	return 0 ;
}
