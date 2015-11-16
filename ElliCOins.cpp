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
#define mod 1000000007
using namespace std ;
long long int fact[100001];
ll int arrays[100001];

void findFactorial()
{

    fact[0]=1;
    int i=1;
    while(i<=100000)
    {
        fact[i]=(fact[i-1]*i)%mod;
        i++;
    }
}
void sumarray()
{
	long long int sum=0;
	arrays[0]=0;
	arrays[1] = 1;
	FOR(2,100000)
	   arrays[i] = (i+ arrays[i-1]);
	
}
int main() {
	findFactorial();
	sumarray();
	int t;
	s(t);
	while(t--){
		int n;
		s(n);
		ll int sum = 0;
		ll int rep=fact[n-1];
		ll int prev,next;
		ll int totalprev,totalgreater,sumprev,sumgreater;
		for(int i=1;i<=n;i++)
		{
			sumprev=arrays[i-1]%mod;
			sumprev=(sumprev*rep)%mod;
					
			totalprev=i-1;
			totalprev = (totalprev*rep)%mod;
	
			prev=abs(sumprev-((totalprev*i)%mod))%mod;
			
			sumgreater=(arrays[n]-arrays[i-1])%mod;
			sumgreater = (sumgreater*rep)%mod;
			
			totalgreater=n-i+1;
			totalgreater= (totalgreater*rep)%mod;
			
			next=abs(((totalgreater*i)%mod)-sumgreater)%mod;
			sum=(sum+(prev)+(next))%mod;
		}
		cout<<sum<<endl;
	/*	sum=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			sum= (sum+ (abs(i-j)*rep)%mod)%mod;
		}
		cout<<sum<<endl; */
	
}	return 0 ;
}

