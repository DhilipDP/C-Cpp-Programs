#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define rep(a,b,c) for(int c=a ; c<=b ; ++c)
#define pii pair<int , int>
#define vi vector<int>
#define vs vector<string>
#define vi_it vector<int> :: iterator
#define vs_it vector<string> :: iterator
#define mp(a,b) make_pair(a,b)


using namespace std;
string grid[1005] ;
int val[1005][1005];
bool vis[1005][1005];
int n,m,k;
int dp[1005][1005];

bool valid(int r,int c)
{
	return (r>=0 && r<n && c>=0 && c<m && grid[r][c]=='*');
}


bool vd(int r,int c)
{
	return (r>=0 && r<n && c>=0 && c<m && grid[r][c]=='.');
}


void pop()
{
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			val[i][j]=0;
			if(grid[i][j]=='.')
			{
				if(valid(i-1,j)) val[i][j]++;
				if(valid(i+1,j)) val[i][j]++;
				if(valid(i,j+1)) val[i][j]++;
				if(valid(i,j-1))  val[i][j]++;
				
			}
		}
	}
}



void solve(int r,int c, int &ct)
{
	
	ct += val[r][c] ;
	
	cout<<ct<<endl;
	for(int i=r-1 ; i>=0 && grid[i][c] == '.' ; i--)
		cout<<"a",ct += val[i][c];

	cout<<ct<<endl;

	
	for(int i=r+1 ; i<n && grid[i][c] == '.' ; i++)
	cout<<"b",	ct += val[i][c]; 	
	
	
	cout<<ct<<endl;
	for(int j=c-1 ; j>=0 && grid[r][j] == '.' ; j--)
		cout<<"c",ct += val[r][j];
		
		
	cout<<ct<<endl;
	for(int j=c+1 ; j<m && grid[r][j] == '.' ; j++)
		cout<<"hi",ct += val[r][j];
	
	cout<<ct<<endl;
/*	if(!vd(i,j) || vis[i][j])	
		return  ;
	
	if(dp[i][j]!=-1)
		return dp[i][j];
//	cout<<i<<" "<<j<<" "<<c<<endl;
	vis[i][j]=true ;
	c += val[i][j] ;
	solve(i,j+1,c) ; solve(i,j-1,c) ; solve(i+1,j,c) ; solve(i-1,j,c) ;*/
}

int main()
{
	s(n); s(m) ; s(k);
	rep(0,n-1,i) cin>>grid[i];
	
	pop();
	while(k--)
	{
		memset(vis,false,sizeof vis);
		memset(dp,-1,sizeof dp);
		int r,c ;
		s(r);s(c) ;
		int ans=0;
		(solve(r-1,c-1,ans));
		p(ans);
	}
	
	return 0;
}
