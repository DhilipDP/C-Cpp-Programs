#include<iostream>
#include<vector>


using namespace std ;
vector<vector<bool> > pal(10000,vector<bool> (10000,false)) ;



void init(string s)
{
	int n = s.length() ;
	for(int i=0 ; i<n ; i++)
		pal[i][i] = true ;
	for(int len = 2 ; len <= n ; len++)
	{
		for(int i=0 ; i<=n-len ; i++)
		{
			int j = i+len-1 ;
			if(len==2)
				pal[i][j] = (s[i]==s[j]) ;
			else
				pal[i][j] = (pal[i+1][j-1] && s[i]==s[j]) ;
		}
	}
}



void palPartition(string s,int st,int end,vector<string> t ,vector<vector<string> > &v)
{
	
//	vector<vector<string> > res; 
	if(st > end){
			v.push_back(t);
		return ;
	}
	for(int i=st ; i<=end ; i++)
	{
	//	cout<<st<<" "<<end<<" "<<i<<endl;
		if(pal[st][i])
		{
			//cout<<" true "<<st<<" "<<i<<endl;
			t.push_back(s.substr(st,i-st+1));
			palPartition(s,i+1,end,t,v);
		
			t.pop_back();
		}
	}
}

int main()
{
	string s = "mamam" ;
	init(s);
	vector<vector<string> > v; 
	vector<string> t;
	palPartition(s,0,s.length()-1,t,v) ;
	for(vector<vector<string> > :: iterator it = v.begin() ; it != v.end() ; it++)
	{
		vector<string> p = *it ;
		for(vector<string> :: iterator i = p.begin() ; i!=p.end() ; i++)
			cout<<*i<<" ";
		cout<<endl;
	}
}
