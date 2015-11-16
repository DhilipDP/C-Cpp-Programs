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
#define vlli vector<long long int>
#define vpii vector<pair<int,int> >
#define vs vector<string>
#define vi_it vector<int> :: iterator
#define vs_it vector<string> :: iterator


#define mp(a,b) make_pair(a,b)


using namespace std ;


bool comp(const int &a, const int &b)
{
	return a < b ;
}


void search(vlli A , ll int low , ll int high , ll int key , ll int &ans)
{
	if(low > high)
		return ;
	ll int mid = low + (high - low) / 2 ;
	if( A[mid] >= key )
	{
		ans = mid ;
		search(A,mid+1,high,key,ans) ;
	}
	else
		search(A,low,mid-1,key,ans) ;
 }
int main() {
	ios :: sync_with_stdio(false);

	int t ;
	s(t) ;
	while(t--)
	{
		int n ;
		s(n) ;
		vlli A(n);
		vlli B(n);
		map<int , int > m;
		rep(0,n-1,i){
			sll(A[i]) ;
			if(i)
				assert(A[i] <= A[i-1]);
		}
		rep(0,n-1,i)
		{
			sll(B[i]) ;
			if(i)
				assert(B[i] <= B[i-1]);
		}
		int maxi = 0;
	///	sort(B.begin() , B.end() , comp) ;
		rep(0,n-1,i)
		{
			ll int index = -1;
		//	search(B,0,n-1,A[i],index) ;
			
			int l = 0 , h = n-1 ,m ;
			while( l <= h)
			{ m =(l+h)/2 ;
			  if(B[m] >= A[i])
			  	{
			  		index = m;
			  		l = m+1;
			  	}
			  	else
			  		h = m-1;
				
			} 
		
			if(index != -1){
				if(index -i > maxi)
					maxi = index - i;
			}
		}
		pll(maxi);
		 
	}

	return 0;
}
