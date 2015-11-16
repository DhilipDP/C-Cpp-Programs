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

int n ;
vi arr(1000002);
vi res(1000002);
map<int , bool> h ;

int index;

int change(int d)
{
		index = 0;
		rep(0,n-2,i)
		{
			cout<<i<<" :"<<endl;
			if(((arr[i] + arr[i+1]) % d ) == 0  && (!h[i+1]) && (!h))
					cout<<"hi"<<endl,res[index] = (arr[i]+arr[i+1])/d, h[index] = true ,i++;
			else
				res[index] = arr[i];
			index++;
		}
		res[index++] = arr[n-1];
			rep(0,index-1,i)
			cout<<res[i]<<" ";
		cout<<endl;
	return index;
	
}
int main() {
	ios :: sync_with_stdio(false);

	int t ; s(t) ;
	
	while(t--)
	{
		 s(n) ;
		rep(0,n-1,i)
			s(arr[i]);
		int d ; s(d);
		
		while(1)
		{
			change(d);
			if(index==n)
				break;
			n = index ;
			arr = res;
		}
	
		rep(0,index-1,i)
			cout<<res[i]<<" ";
		cout<<endl;
	}
	return 0;
}
