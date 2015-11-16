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

int dp[10004][10004];

int m , n ,a,b, c;


void init()
{
	rep(0,10003,i)
		dp[i][0] = a , dp[0][i] = b;
}
void solve(string A,string B){

	int i,j;
//	cout<<A<<" "<<B<<endl;	
	int left,top,corner;
	for(i=1 ; i<=m ; i++){
		for(j=1 ; j<=n ; j++){
		//	cout<<i<<" "<<j<<" : "<<dp[i][j]<<endl;
			left = dp[i][j-1];
			left += a;
			top = dp[i-1][j];
			top += b;
			corner = dp[i-1][j-1];
			corner += ((A[i-1] != B[j-1]) ? c : 0);
		//	cout<<left<<" "<<top<<" "<<corner<<" "<<endl;
			dp[i][j]= min(left,min(top,corner));
			//cout<<dp[i][j]<<endl;
		}
		//cout<<endl;
	}

}


bool anagrams(string A,string B)
{
	int h[26];
	memset(h,0,sizeof(h));
	rep(0,m-1,i)
		h[A[i]-97]++;
	rep(0,n-1,i)
		h[B[i]-97]--;
	rep(0,25,i)
		if(h[i]!=0)
			return false;
	return true;
}

int main() {
//	ios :: sync_with_stdio(false);
	int t ; s(t) ;
	while(t--)
	{
		string A,B;
	
		init();
	//	cout<<"ll";
		cin>>A;
	//	cout<<"HI";
		cin>>B ;
	//	cout<<"hj";
		s(a) , s(b) , s(c);
		m = A.length() , n=B.length();
			if(anagrams(A,B))
		{
			cout<<"0"<<endl;
			continue;
		}
	
		solve(A,B);
		p(dp[m][n]);
	}	
	return 0;
}

