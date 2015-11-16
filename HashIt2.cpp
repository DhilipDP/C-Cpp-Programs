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


map < int , string > m ;
map< string , int> u;
map <string , bool> p;


int h(string s)
{
	int ans = 0; 
	for(int i=0 ; i<s.length() ; i++)
		ans += ((i+1)*s[i]%101)%101;
	return (ans*19)%101;
}

void add(string s)
{
	if(p[s])
		return ;
//	cout<<"Adding "<<s<<" ";
	int index = h(s) % 101 ;
	if( m[index] =="")
		m[index]=s , u[s] = index , p[s]=true;
	else{
		int c = 0 ;
		for(int j=1 ; j<=19 ; j++)
		{
			int ind = (h(s) + (j*j)%101 + (23*j)%101) % 101 ;
			if(m[ind]=="")
			{
				m[ind] = s;
				u[s] = ind;
				//cout<<" : "<<ind;
				p[s] = true;
				break;
			}
		}
	}
//	cout<<endl;
}


void delet(string word)
{
	if(!p[word])
		return ;
	m[u[word]] = "";
	u[word] = 0;
	p[word] = false;
}
int main() {
	
	ios :: sync_with_stdio(false);
	int t  ; s(t) ;
	while(t--)
	{
		m.clear() ;
		
		int n ; s(n) ;
		while(n--)
		{
			string s ; cin>>s ;
			string op = s.substr(0,3) ;
			string word = s.substr(4,s.length()-4);
			if(op=="ADD")
				add(word);
			else
				delet(word);
		}
		vector<string> ans ;
		vector<int> val;
		int c = 0,i=0;
		rep(0,100,j)
		{
			if(m[j]!="")
			c++ , ans.push_back(m[j]) , val.push_back(i);
			i++;
		}
		cout<<c<<endl;
		i=0;
		for(vector<string> :: iterator it = ans.begin() ; it != ans.end() ;  it++)
			cout<<val[i++]<<":"<<*it<<endl;
		cout<<endl;
	}
	
	return 0;
}
