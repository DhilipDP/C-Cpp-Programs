#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;


struct graph{
	vector<int> adj ;
};



bool dfs(graph nodes[] , int n , int v,bool visited[],int count){
		if(v==0 && visited[v] == true && count==n)
		{
		return true ;
		}
		visited[v] = true ;
		vector<int> num = nodes[v].adj ;
		bool res = false ;
		for(int i=0 ; i<num.size() ; i++){
				if(num[i] == 0 || visited[num[i]] == false){
					res |= dfs(nodes,n,num[i],visited,count+1);
			}
		}
		return res ;
		
		
}

bool isChained(graph nodes[] , int n)
{
	bool visited[n] ;
	memset(visited,false,sizeof(visited) ) ;
	
	int count  = 0;
	return dfs(nodes,n,0,visited,count) ;
	
	
}


bool hasPath(vector<string> v)
{
		int n = v.size() ;
		if(n <= 1)
			return true ;
		graph nodes[n] ;
		for(int i=0 ; i<n ; i++){
			string str = v[i] ;
			char last = str[str.length()-1] ;
			for(int j=0 ; j<n ; j++)
				if(i!=j && v[j][0] == last){
					nodes[i].adj.push_back(j) ;
					cout<<i<<" -- "<<j<<endl;	
				}
				
		}
		
		return isChained(nodes,n) ;
		
}

int main()
{
//	string arr[] = {"nandu","yak","kak" , "kur" , "raj" ,"uday" ,"jan"} ;
//	int n = 7 ;
	
	string arr[] = {"ask","tea" ,"kent"} ;
	int n = 3;
	vector<string> v(arr,arr+n) ;
	cout<<hasPath(v);
}
