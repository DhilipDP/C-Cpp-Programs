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
int main()
{
	int t ; s(t) ;
	while(t--)
	{
		string str,  reserve ;
		int s_ptr =0, r_ptr =0;
		cin>>str>>reserve ;
		sort(reserve.begin() , reserve.end());
		while(s_ptr < str.length())
		{
			if(r_ptr < reserve.length() && str[s_ptr] > reserve[r_ptr])
				str[s_ptr] = reserve[r_ptr++];
			s_ptr++;
		}
		cout<<str<<endl;
	}
	return 0;
}
