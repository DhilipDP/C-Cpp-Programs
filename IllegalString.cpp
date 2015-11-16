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


void update(string s , int &a , int &b,int &other)
{
	
	int n = s.length() ;
	if(n==1)
	{
		other += 1 ;
		return ;
	}
	b += n ;
	a += n/2;
	
	if(n&1)
		a++;
}
int main() {
	ios :: sync_with_stdio(false);

	int t ; s(t) ;
	
	string s ;  cin>>s ; 
	
	int other = 0, min_c = 0 , max_c = 0 , i=0;
	
	while(i < t)
	{
		if((s[i]=='v' || s[i]=='w'))
		{
			
			string temp = "";
			while(i<t && (s[i] == 'v' || s[i] == 'w')){
			
				s[i]=='v' ? temp += "v" : temp+="vv" ;
				i++;}
			
			update(temp,min_c,max_c,other);
		/*	int n = temp.length() ;
	if(n==1)
	{
		other += 1 ;
	
	}
	else{
	max_c += n ;
	min_c += n/2;
	
	if(n&1)
		min_c++;
	}	*/
		}
		else{
		
			other++;
		i++;
	}
//		cout<<i<<" "<<other<<endl;
	}
	cout<<other+min_c<<" "<<other+max_c<<endl;
	
	return 0;
}
