#include<bits/stdc++.h>
 
#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define rep(a,b,c) for(int c=a ; c<=b ; ++c)
#define pii pair<int , int>
#define mp(a,b) make_pair(a,b)
#define SIZE 100001
 
using namespace std ;
 
ll int find_ans(ll int a, ll int b,ll int c ,ll int x)
{
	return (a*x*x ) + (b*x) + c;
}
 
 
ll int solve(ll int a , ll int b , ll  int c , ll int k, ll int low,ll int high)
{
//	cout<<low<<" "<<high<<endl;
	if(low > high)
		return -1 ;
ll	int mid = low+(high - low) / 2;
	
	ll	int ans1 = find_ans(a,b,c,mid) ;
	ll 	int ans2 = find_ans (a,b,c,mid+1) ;
	ll	int ans3 = find_ans (a,b,c,mid-1) ;
	
	//cout<<ans1<<endl;
	if(ans1 >= k && ans3 < k)
		return mid ;
	if(ans2 >= k && ans1 < k)
		return mid+1;
	if( ans1 < k)
		return solve(a,b,c,k,mid+1,high);
	return solve(a,b,c,k,low,mid-1);
		
}
 
int main() {
	ios :: sync_with_stdio(false);
 
	int t ;
	s(t) ;
	
	while(t--)
	{
		ll int a,b,c,k;
		sll(a) ; sll(b) ; sll(c) ; sll(k) ;
		
		printf("%lld\n",solve(a,b,c,k, 0 ,SIZE-1)) ; 
	}
	return 0;
}
