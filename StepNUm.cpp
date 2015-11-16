#include<iostream>
#include<vector>

using namespace std ;

struct graph{
	vector<int> adj;
};

graph nodes[10] ;
void init()
{
//	for(int i=1 ; i<=9 ; i++)
		nodes[0].adj.push_back(1);
	for(int i=1 ; i<=8 ; i++)
		nodes[i].adj.push_back(i-1) , nodes[i].adj.push_back(i+1) ;
	nodes[9].adj.push_back(8) ;
}

void dfs(int v,int &A,int &B , vector<int> &ans,int hash[],int num)
{
//			cout<<v<<endl;
		hash[v] = true ;
		if(num > B)
			return ;
		if(num >= A && num <=B){
			cout<<num<<endl;
			ans.push_back(num);
			return ;
		}
		for(int i=0 ; i<nodes[v].adj.size() ; i++){
		
			if(hash[nodes[v].adj[i]] == 0 )
//			cout<<nodes[v].adj[i]<<endl;//	
dfs(nodes[v].adj[i],A,B,ans,hash,num*10 + nodes[v].adj[i]);
			}
}


vector<int> stepnum(int A,int B)
{
	init() ;
	
	vector<int> res;
	
	for(int i=0 ; i<=9 ; i++)
	{
		cout<<i<<endl;
	//	cout<<nodes[i].adj.size()<<endl;
		int hash[10] = {0};
		dfs(i,A,B,res,hash,0) ;
		cout<<"done"<<endl;
	//	break;
	}
	return res;
		
}

int main()
{
	vector<int> v= stepnum(10,100) ;
	for(int i=0 ; i<v.size() ; i++)
		cout<<v[i]<<" ";
}
