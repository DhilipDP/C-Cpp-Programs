


#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define pll(a) printf("%lld\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define rep(a,b,c) for(int c=a ; c<=b ; ++c)
#define pii pair<int , int>
#define vi vector<int>
#define vs vector<string>
#define vi_it vector<int> :: iterator
#define vs_it vector<string> :: iterator
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007


using namespace std ;


int arr[1000002] ;
int dp[1000002] ;
int n;



int lis(){

	
	int i,j;
	
	for(i=0 ; i<n ; i++)
		dp[i]=1;

	int maxi = 1;
	for(i=1 ; i<n ; i++){
		for(j=0 ; j<i ; j++){
			if(arr[i] % arr[j]==0 && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
				if(dp[i] > maxi)
					maxi = dp[i];			
			}
		}
		
	}
	return maxi;
}
int main() {



	ios :: sync_with_stdio(false);
	
	int t ; s(t) ;
	while(t--)
	{
		s(n);
		rep(0,n-1,i)
			s(arr[i]);
		p(lis());
	}

	return 0;
}
	
