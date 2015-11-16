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

vi arr(25) , dup(25);
int n;

int fun()
{
	int s = 0 , i=1 , j=n;
	while(i <= n/2){
		s +=  abs(arr[j]-arr[i]);
		i++ , j--;
	}
	return s;
}


int fun1()
{
	int s = 0 , i=1 , j=n;
	while(i <= n/2){
		s +=  abs(dup[j]-dup[i]);
		i++ , j--;
	}
	return s;
}

int main() {
	ios :: sync_with_stdio(false);

	int t ; s(t) ;
	while(t--)
	{
		s(n);
		rep(1,n,i){
			s(arr[i]);
			dup[i] = arr[i];		
		}
		int maxi = fun();
		int m2 = maxi ;
		rep(2,n-1,i)
		{
			if(arr[i-1] % 2 ==0 && arr[i+1] % 2==0)
			{
				int temp = arr[i];
				arr[i] = (arr[i-1] + arr[i+1])/2 ;
				if(temp != arr[i])
				maxi = max(maxi , fun());
			}
			if(dup[i-1] % 2 ==0 && dup[i+1] % 2==0)
			{
				int temp = dup[i];
				dup[i] = (dup[i-1] + dup[i+1])/2 ;
				if(temp != arr[i])
				m2 = max(m2 , fun1());
				dup[i] = temp;
			}
		}
		p(max(maxi,m2));
	}	
	return 0;
}
