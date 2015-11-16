#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std ;


#define mod 1000000007
int main(){
 freopen("C:\\Users\\Nandu Vinodan\\Desktop\\dbg3\\i3.txt", "r", stdin);
 freopen("C:\\Users\\Nandu Vinodan\\Desktop\\dbg3\\o3.txt", "w", stdout);
//FILE *fp = fopen("C:\\Users\\Nandu Vinodan\\Desktop\\dbg3\\o2.txt","w");
int t;
cin>>t;
while(t--)

{

//frre
//frre
int N;
cin>>N;
int tow[N]; 
for(int i=0 ; i<N ; i++)
	cin>>tow[i];
// nonnegative tower heights
int hl[N] ,hr[N] ; // highest-left and highest-right
memset(hl,0,sizeof(hl));
memset(hr,0,sizeof(hr));
for (int i = 0; i < N; i++) 
	hl[i] = max(tow[i], (i!=0)?hl[i-1]:0);
for (int i = N-1; i >= 0; i--)
	 hr[i] = max(tow[i],i<(N-1) ? hr[i+1]:0);
int ans = 0;

for (int i = 0; i < N; i++) 
	ans = (ans + min(hl[i], hr[i]) - tow[i])%mod;
	
cout<<ans<<endl;

}

}
