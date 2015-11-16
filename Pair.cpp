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
#define plli pair<ll int,ll int>
#define mp(a,b) make_pair(a,b)


using namespace std ;

int main() {
    unsigned ll int n,k;
    sll(n);
    sll(k);
    ll int i;
    ll int arr[n];
    map<plli,int> m;
    map<int ,int> hash;
    FOR(0,n-1,i)
    {    sll(arr[i]);
         hash[arr[i]]=1;
    }  
    ll int count = 0;
    FOR(0,n-1,i){
        ll int pair1 = arr[i]+k;
        ll int pair2 = arr[i]-k;
        plli p1 = mp(arr[i],pair1);
        plli p2 = mp(arr[i],pair2);
        plli p3 = mp(pair1,arr[i]);
        plli p4 = mp(pair2,arr[i]);
        if( hash[pair1]==1 && (m[p1]==0 || m[p3]==0) ){
           m[p1]=1;
           m[p3]=1;
        //   cout<<arr[i]<<" "<<pair1<<endl;
            count++;
        }
        if(hash[pair2]==1 && (m[p2]==0 || m[p4]==0)){
            m[p2]=1;
            m[p4]=1;
          //  cout<<arr[i]<< " "<<pair2<<endl;
            count++;
        }
    }
    printf("%lld",count);
}
