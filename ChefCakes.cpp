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
map<int , bool> hm;
int main()
{
	int t ; s(t) ;
	while(t--){
		hm.clear();
		int n , m ;
		s(n) ; s(m) ;
		int count = 0 ;
		int cur_pos = 1 ;
		while(true)
		{
			if(hm[cur_pos])
				break;
			count++ ;
			hm[cur_pos]=true;
			if(cur_pos > (n-m))
				cur_pos -= (n-m);
			else
			cur_pos = cur_pos + m ;	
			}
		if(count!=n)
			{
			cout<<"No ";
			p(count);
		}
		else
		cout<<"Yes"<<endl;
	}
	return 0;
}
