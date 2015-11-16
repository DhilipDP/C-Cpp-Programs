#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;



void subset(vector<vector<int> > &res,int i ,int n,vector<int> v,vector<int> t)
{
	
//	cout<<i<<endl;
	if(i > n){
//		cout<<"Pushing :"<<endl;
		
		res.push_back(t);
		return ;
	}

	subset(res,i+1,n,v,t) ;
	t.push_back(v[i]);
	
	subset(res,i+1,n,v,t);

}

int main()
{
	vector<int> v ;
	v.push_back(12) ;
	v.push_back(13) ;
//	v.push_back(3) ;
	vector<vector<int> > res ;
	vector<int> temp ;
	 subset(res,0,v.size()-1,v,temp) ; 
	// sort(res.begin(),res.end());
	for(vector<vector<int> > :: iterator it = res.begin() ; it != res.end() ; it++)
	{
		vector<int> p = *it ;
		for(vector<int> :: iterator i = p.begin() ; i!=p.end() ; i++)
			cout<<*i<<" ";
		cout<<endl;
	}
}

