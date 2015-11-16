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

long long int N , max_res , min_res ;
vector< ll int> arr;

ll int max(ll int a , ll int b) { return a > b ? a : b ;
}


ll int min(ll int a , ll int b) { return a < b ? a : b ;
}
void find(int index, int prod)
{
	if(index >= N)
		return ;
	cout<<index<<" "<<prod<<endl;
	find(index+1 , prod) ;
	prod *= arr[index] ;
	max_res = max(max_res,prod);
	min_res = min(min_res,prod);
	find(index+1,prod);
}

int main()
{
	int t ; s(t) ;
	while(t--)
	{
		max_res = INT_MIN ;
		min_res = INT_MAX ;
		s(N) ;
		arr.clear();
		arr.resize(N);
		ll int r = 1;
		rep(0,N-1,i) 
		{
		sll(arr[i]);
			if(arr[i]!=0)
		 r*=arr[i];
	
	}
	printf("%lld\n",r);
		
		find(0,1) ;
		printf("%lld %lld\n",max_res,min_res);
	}
	return 0;
}
