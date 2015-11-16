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

int toggle(char c)
{
	return c=='*' ? '.' : '*';
}


bool valid(int i, int j,vector<vector<bool> > h)
{
	if(i>=0 && i<3 && j>=0 && j<3 && !h[i][j])
		return  true ;
	return false;
}

bool check(vector<string> &v)
{
	bool flag = true ;
	rep(0,2,i){
		rep(0,2,j){
			if(v[i][j]=='*')
			{
				return false;
			}
		}
	}
	return true;
}



int solve(vector<string> v,int clicks , int i, int j,vector<vector<bool> > h)
{
//	cout<<i<<" "<<j<<endl;
	if(!valid(i,j,h))
		return INT_MAX ;	
	h[i][j] = true;
	if(check(v)){
		cout<<clicks<<endl;
		return clicks;
	}
	int ans ;
	if(j!=2)
	 ans =  (solve(v,clicks,i,j+1,h)) ;
	else
	ans = solve(v,clicks,i+1,0,h);
	clicks++;
	v[i][j] = toggle(v[i][j]);
	if(valid(i-1,j,h))
	{
		v[i-1][j] = toggle(v[i-1][j]);
		ans = min(ans , solve(v,clicks,i-1,j,h));
	}
	if(valid(i+1,j,h))
	{
		v[i+1][j] = toggle(v[i+1][j]);
		ans = min(ans,solve(v,clicks,i+1,j,h));
	}
	if(valid(i,j-1,h))
	{
		v[i][j-1] = toggle(v[i][j-1]);
		ans  = min(ans ,solve(v,clicks,i,j-1,h));
	}
	if(valid(i,j+1,h))
	{
		v[i][j+1] = toggle(v[i][j+1]);
		ans = min(ans,solve(v,clicks,i,j+1,h));
	}
//	cout<<i<<" "<<j<<" "<<ans<<endl;
	return ans;
}


int min_clicks(vector<string> v,int clicks,int i, int j)
{
	if(i<0 || i>2 || j<0 || j>2 )
		return INT_MAX ;
	
	
		
	cout<<i<<" "<<j<<endl;
	bool flag = true ;
	rep(0,2,i){
		rep(0,2,j){
			if(v[i][j]=='*')
			{
				
				flag = false ;
				break;
			}
		}
	}
	
	if(flag)
		return clicks;

	int ans =  INT_MAX ;
	rep(0,2,i){
		rep(0,2,j){
			if(v[i][j]=='*')
			{   
			    v[i][j] = toggle(v[i][j]);
				if(i-1 >= 0)
					v[i-1][j] = toggle(v[i-1][j]);
				if(i+1 < 3)
					v[i+1][j] = toggle(v[i+1][j]);
				if(j-1 >=0 )
					v[i][j-1] = toggle(v[i][j-1]) ;
				if(j+1 < 3)
					v[i][j+1] = toggle(v[i][j+1]);
				ans = min(ans,min_clicks(v,clicks+1,i,j));
			}
		}
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(false);
	int t ; s(t) ;
	while(t--)
	{
		vector<string> v(3);
		rep(0,2,i)
			cin>>v[i];
		vector<vector<bool> > h(3,vector<bool> (3,false));
		p(solve(v,0,0,0,h));
	}
	
	return 0;
}
