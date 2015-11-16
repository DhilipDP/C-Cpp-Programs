#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
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


using namespace std ;


int n , m ;
vs v;
int h[26];



bool valid(int r ,int c)
{
	if(r >= 0 && r<n && c>=0 && c<m)
		return true ;
	return false;
}

bool t1(int r,int j)
{
	if(r== 0 || j==0)
		return false;
	memset(h,0,sizeof h);

	h[ v[r-1][j-1] - 97]++;
	h[v[r-1][j] - 97]++;
	h[v[r][j-1] -97]++;
	h[v[r][j]-97]++;
	
		if(h['c' -97]==1 && h['s'-97]==1 && h['a'-97]==1 && h['u'-97]==1)
		return true;
	return false;	

		
}

bool t2(int r,int j)
{
	if(r== 0 || j==m-1)
		return false;
	memset(h,0,sizeof h);

	h[ v[r-1][j+1] - 97]++;
	h[v[r-1][j] - 97]++;
	h[v[r][j+1] -97]++;
	h[v[r][j]-97]++;
	
	if(h['c' -97]==1 && h['s'-97]==1 && h['a'-97]==1 && h['u'-97]==1)
		return true;
	return false;	

		
}

int t3(int r,int j)
{
	if(r== n-1 || j==0)
		return 0;
	memset(h,0,sizeof h);

	h[ v[r+1][j] - 97]++;
	h[v[r+1][j-1] - 97]++;
	h[v[r][j-1] -97]++;
	h[v[r][j]-97]++;
	
	if(h['c' -97]==1 && h['s'-97]==1 && h['a'-97]==1 && h['u'-97]==1)
		return 1;
	return 0;	

		
}

int t4(int r,int j)
{
	if(r== n-1 || j==m-1)
		return 0;
	memset(h,0,sizeof h);

	h[ v[r+1][j+1] - 97]++;
	h[v[r+1][j] - 97]++;
	h[v[r][j+1] -97]++;
	h[v[r][j]-97]++;
	
		if(h['c' -97]==1 && h['s'-97]==1 && h['a'-97]==1 && h['u'-97]==1)
		return 1;
	return 0;	

		
}
int main() {
	ios :: sync_with_stdio(false);

	s(n) ; s(m) ;
	
	rep(1,n,i)
	{
		string s ; cin>>s ;
		v.push_back(s);
	}
	
	int c = 0;
	rep(0,n-1,i)
	{
		rep(0,m-1,j)
		{
			if(v[i][j]=='c'){
		//		cout<<t1(i,j) <<" "<<t2(i,j)<<" "<<t3(i,j)<<" "<<t4(i,j)<<endl;
				c += (t1(i,j) + t2(i,j) + t3(i,j) + t4(i,j));
			}
		}
	}
	
	p(c);
	return 0;
}
