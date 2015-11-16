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


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

int main() {

	int n ;
	s(n);
	int arr[n+1];
	int ones=0,twos=0,threes=0;
	FOR(1,n){
		s(arr[i]);
		if(arr[i]==1)
			ones++;
		if(arr[i]==2)
			twos++;
		if(arr[i]==3)
			threes++;
	}
	int num = min(min(ones,twos),threes);
	if(num==0)
		p(0);
	else{
		p(num);
		int hash[n+1];
		memset(hash,0,sizeof(hash));
		FOR(1,num){
			bool one=false,two=false,three=false;
			int c = 0;
			for(int i=1 ; i<=n ; i++){		
				if(hash[i]!=1 && arr[i]==1 && !one )
					one = true,printf("%d ",i),c++,hash[i]=1;
				if(hash[i]!=1 && arr[i]==2 && !two)
					two = true,printf("%d ",i),c++,hash[i]=1;
				if(hash[i]!=1 && arr[i]==3 && !three)
					three = true,printf("%d ",i),c++,hash[i]=1;
				if(c==3)
				 break;
			}
			cout<<endl;
		}
	}return 0 ;
}

