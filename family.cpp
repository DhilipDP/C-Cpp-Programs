#include<iostream>
#include<map>
#include<vector>

using namespace std ;

int main()
{
	
	int n ;
	cin>>n ;
	map<string , vector<string> > rel ;
	for(int i=0 ; i<n ; i++)
	{
		string child , father ;
		cin>>child >> father ;
		rel[father].push_back(child) ;
	}
	int gc = 0;
	string name ; cin>>name ;
	
	/*
	for(map<string , vector<string> > :: iterator it = rel.begin() ; it != rel.end() ; it++)
	{
		cout<<it->first<<" : "<<endl ;
		vector<string > s = it->second ;
		for(int i=0 ; i<s.size() ; i++)
			cout<<s[i]<<" ";
		cout<<endl;
	}
	*/
	
	
	vector<string> children = rel[name] ;
	
	for(int i=0 ; i<children.size() ; i++)
	{
		gc += rel[children[i]].size() ;
	}
	cout<<gc<<endl ;
}


