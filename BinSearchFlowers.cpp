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


using namespace std;
int N,K ;
vi pos;



bool check(int range)
{
	int temp = K ;
	int  cur = pos[0] + range ;
	temp-- ;
	for(int i=1 ; i<N ; i++)
	{
		if(cur + range >= pos[i]) continue ;
	
		if(temp==0)
		return false ;
		
		temp--;
		cur = pos[i] + range;
			
	}
	return true;
}

int solve(int low , int high)
{
	int mid ;
	while(low <= high){
			mid = (low + (high-low)/2);
		bool m1 = check(mid) ;
	
		bool m2 = check(mid-1);
		if(m1 && !m2)
			break;
		if(!m1)
		{
			low = mid+1;
		}
		else
			high= mid-1;
	}
	return mid ;
}
int main()
{
	
	s(N) ; s(K) ;
	pos.resize(N);
	rep(0,N-1,i) s(pos[i]) ;
	sort(pos.begin() , pos.end());
	p(solve(0,100000000));
	return 0;
}
