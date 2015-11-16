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


int main() {
//	ios :: sync_with_stdio(false);

	string up , lo ;
	int i = 122 , j=90 , t= 26;
	while(t--)
	{
		up += (char)j;
		lo += (char)i;
		i--,j--;
	}
//	cout<<up<<endl<<lo;
	 int n ;
	 s(n) ;
	int  d=0;
	 bool flag = true;
	 while(d<n)
	 {
		 string str;
		 getline(cin,str);
		 if(str=="")
		 {
		 	continue;
		 }
		 d++;
		 int k ; s(k) ;
		rep(0,str.length()-1,i)
	 	{
	 		
			if(islower(str[i]))
	 			str[i] = lo[((122-str[i])+k)%26] ;
	 		else if(isupper(str[i]))
	 			str[i] = up[((90-str[i])+k)%26];
	 		//cout<<s[i]<<endl;
	 	}
	 	cout<<str<<endl;
	 	
	 }
	return 0;
}
