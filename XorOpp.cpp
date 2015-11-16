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

int getXor(vi arr, int i, int j)
{
	sort(arr.begin()+i , arr.begin()+j+1);
//	for(int l=0 ; l<arr.size() ; l++)
//	cout<<arr[l]<<" ";
//	cout<<endl;
	return arr[i] ^ arr[i+1] ^ arr[i+2] ^ arr[i+3];
}
int main()
{
	int t ; s(t) ;
	rep(1,t,k)
	{
		int n  ;s(n) ;
		vi arr(n) ;
		
		vector<vector<vector<int> > > v(n,vector<vector <int> >(n, vector<int>(4))) ;

		rep(0,n-1,i) s(arr[i]) ;
		
		for(int len=4 ; len <=n ; len++)
		{
			for(int i=0 ; i<=(n-len) ; i++)
			{
				int j= i+len-1 ;
				if(len==4)
				{
					vector<int> r(4) ;
					for(int p=0,q=i ; p<4 ; p++ )
						r[p] = arr[q++];
					sort(r.begin() , r.end());
					v[i][j]=r;
				}
				else{
					int val = arr[j] ;
					int p=3;
					vector<int> r = v[i][j-1];
					while(p>=0 && r[p] >= val )
					p--;
					p++;
					if(p>=0 && p<4) r[p]=val; 
					
					v[i][j] = r;
				}
			}
		}
		
		
		for(int i=0 ;i<n ; i++){
			for(int j=0 ; j<n ; j++)
			{
				vector<int> r = v[i][j];
				for(int i=0 ; i<4 ; i++) cout<<r[i]<<" ";
				cout<<"    ";
			}
			cout<<endl;
		}
		int l=0 ,r=0 , res = 0 , t_len =0;
		for(int len = 4 ; len <=n ; len++)
		{
			for(int i=0 ; i<=(n-len) ; i++)
			{
				int j= i+len-1 ;
				int ans = getXor(arr,i,j);
				vector<int> h = v[i][j];
				ans = h[0]^h[1]^h[2]^h[3];
			//	cout<<i<<" "<<j<<" "<<ans<<endl;
			
				cout<<i<<" "<<j<<" "<<ans<<endl;
				if(ans > res  || (ans==res && t_len < len))
				{
					res = ans ;
					t_len =len ;
					l = i;
					r = j;
				}
				
			}
		}
		printf("Case %d:\n%d %d %d\n",k,l+1,r+1,res);
	}
	return 0;
}
