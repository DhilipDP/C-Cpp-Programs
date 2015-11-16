#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define rep(a,b,c) for(int c=a ; c<=b ; ++c)
#define pii pair<int , int>
#define vi vector<int>
#define vs vector<string>
#define vi_it vector<int> :: iterator
#define vs_it vector<string> :: iterator
#define mp(a,b) make_pair(a,b)


using namespace std;
int main()
{
	string s ;
	cin>>s ;
	int n ; s(n);
	while(n--)
	{
		int l,r,k ;
		s(l) ; s(r) ; s(k) ;
		
		string a,b,c ;
		a = s.substr(0,l-1) ;
		b = s.substr(l-1,r-l+1);
		c = s.substr(r,s.length()-r);
		
		
	//	cout<<a<<" "<<b<<" "<<c<<endl;
		k = k % b.length() ;
			
		string rt = b.substr(b.length()-k , k);
		string st = b.substr(0,b.length()-k);
		 b = rt+st;
		 
		 
		// cout<<rt<<" "<<s<<endl;
		s = a+b+c ;
//		cout<<s<<endl;
	}
	cout<<s<<endl;
	return 0;
}
