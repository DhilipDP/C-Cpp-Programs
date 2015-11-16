#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define rep(a,b,c) for(int c=a ; c<=b ; ++c)
#define pii pair<int , int>
#define mp(a,b) make_pair(a,b)

using namespace std ;


bool comp(const pii &a , const pii &b)
{
	return a.first < b.first ;
}

int main() {
	ios :: sync_with_stdio(false);

	int t ;
	s(t) ;
	while(t--)
	{
		int n  , k , i, j;
		s(n) ;
		s(k) ;
	
		vector<pii> rows (n , mp(0,0));
		vector<pii> cols (n , mp(0,0)) ;
	
		rep(0,n-1,i)
		rep(0,n-1,j){
			int val ; s(val) ;
			int temp = rows[i].first ;
			int t2 = cols[j].first ;
			pii r = mp(val+temp,i) ;
			pii c = mp(val+t2,j) ;
			rows[i] = r;
			cols[j] = c;
			//cols.push_back(c);
			
		}
		
		int ans = 0;
		while(k--)
		{
		sort(rows.begin() , rows.end() ,comp) ;
			sort(cols.begin() , cols.end() , comp) ;
			
			if( rows[0].first < cols[0].first)
			{
				ans += rows[0].first ;
				rows[0].first += n ;
				for(int i=0 ; i<n ; i++)
				{
					cols[i].first++;
				}
			}
			
			else
			{
				ans += cols[0].first ;
				cols[0].first += n ;
				for(int i=0 ; i<n ; i++)
				{
					rows[i].first++ ;
				}
			}
		}
		p(ans) ;
			
	}
	return 0;
}
