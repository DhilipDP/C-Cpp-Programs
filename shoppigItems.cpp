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


int arr[10004][3] ;
int n ;
int dp[10004][3];

int fun(int row,int col)
{
	int val = INT_MAX ;
	rep(0,2,i)
		if( i!=col )
			val =  min(val,dp[row][i]);
		return val;
}

int solve_dp()
{
	rep(0,2,i)
		dp[0][i] = arr[0][i] ;
	rep(1,n-1,i)
	{
		rep(0,2,j)
		{
			dp[i][j] = arr[i][j] + fun(i-1,j);
		}
	}
	int res = INT_MAX ;
	rep(0,2,i)
		res = min(res,dp[n-1][i]);
	return res;
}

int solve(int pre , int row, int cost)
{
	
	//cout<<pre<<" "<<row<<" "<<cost<<endl;
	if(row == n)
		return cost;
	int res = INT_MAX ;
	rep(0,2,j)
		if(j != pre)
			res = min(res,solve(j,row+1, cost+arr[row][j]));
	return res;
}

int main() {
	ios :: sync_with_stdio(false);
	
	int t ; s(t) ;
	while( t-- )
	{
			s(n) ;
			rep(0,n-1,i)
				rep(0,2,j)
					s(arr[i][j]);
	//		p(solve(-1,0,0));
			p(solve_dp());
	}
	return 0;
}
