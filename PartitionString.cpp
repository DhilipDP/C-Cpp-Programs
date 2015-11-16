#include<iostream>

#include<vector>


#define rep(a,b,i) for(int i=a ; i<=b ; i++)
#define vs vector<string>
#define vec vector
#define pb push_back

using namespace std ;


bool tab[1000][1000] ;


vec < vs > res ;

void init(string s)
{
	
	int n = s.length() ;
	rep(0,n-1,i) tab[i][i] = 1 ;
	
	rep(2,n,l){
		rep(0,n-l,i)
		{
			int j = i+l-1 ;
			if(l==2)
				tab[i][j] = (s[i]==s[j]) ;
			else
				tab[i][j] = (s[i]==s[j] ) && (tab[i+1][j-1]);
		}
	}
	
}


void solve(string s, int start, vs  arr)
{
	cout<<start<<endl;
	if(start > s.length()-1 ){
		
		for(int i=0 ; i<arr.size() - 1; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		res.pb(arr);
		return ;
	}
	rep(start,s.length()-1,i)
	{
		if(tab[start][i] ){
			cout<<"hll "<<start<<" "<<i<<endl;
			arr.pb(s.substr(start,i-start+1));
			solve(s,start+1 , arr);
			arr.pop_back();
		}
	}
}


int main()
{
	
	
	string s = "nandu" ;
	init(s);
	
		vs v;
	solve(s,0,v);
	
	int m = res.size() ;
	rep(0,m-1,i)
	{
		vs a = res[i] ;
		rep(0,a.size()-1,j)
			cout<<a[j]<< " ";
		cout<<endl;
	}
}
