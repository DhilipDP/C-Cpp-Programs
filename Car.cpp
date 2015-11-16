#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d",a)
#define pll(a) printf("%lld",a)
#define pn printf("\n")
#define pb(a) push_back(a)

#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define rep(a,b,c) for(int c=a ; c<=b ; ++c)
#define pii pair<int , int>
#define vi vector<int>
#define vpii vector< pii >
#define vs vector<string>
#define vi_it vector<int> :: iterator
#define vs_it vector<string> :: iterator
#define mp(a,b) make_pair(a,b)


using namespace std ;


map<int , int> m ;

map<int , bool>  st ;
int main() {
	ios :: sync_with_stdio(false);
	int t ; s(t) ;
	bool set = false ;
	while(t--)
	{
		set = false ;
		m.clear() ;
		st.clear() ;
		vpii pas;
		int n , c ;
		s(n) ; s(c) ;
		
		while(n--)
		{
			int s, e ; s(s) ; s(e) ;
	//		if(st[s])
		
	//			continue;
			pas.pb(mp(s,e));
			st[s] = true ;
			rep(s,e,i){
				if( m[i] == c){
					 set = true;
					continue;
				}
				m[i]++;
			}
		}
		double rev = 0;
		
		
		rep(0,100,i)
			cout<<i<<" : "<<m[i]<<" "<<endl;
		cout<<endl;
		rep(0,pas.size()-1,i)
		{
			
			int s = pas[i].first , e = pas[i].second ;
			
			int o =0, two=0 , th =0;
			double	fair = 0;//(e - s + 1) * 100.00 ;
			cout<<s<<" "<<e<<" "<<fair<<endl;
			rep(s,e,j)
			{
				if(m[j]==1) o++;
				if(m[j]==2) two++;
				if(m[j] >= 3)
					th++;
			}
			
			cout<<o<<" "<<two <<" "<<th<<endl;
			
			o *= 10 , two *= 10 , th *=10;
			fair += (o )  + (two - (0.05 * two)) + (th - (0.07 *th));
			/*
			int peo = 0;
			double dis = 0;
			rep(s,e,j)
				peo = max(peo,m[j]);
			if(peo==2)
				dis = (0.05) * fair ;
			if(peo >= 3)
				dis = (0.07) * fair ;
			fair -= dis;*/
			cout<<fair<<endl;
			
			rev += fair ;
			cout<<rev<<endl;
		}
		
		printf("%lf",rev);
		
		
		pn;
	}
	return 0;
}
