#include<iostream>
#include<utility>
#include<vector>
#define N 6
#define NUM 5
#define FOR(a,b) for(int i=a ; i<=b ; i++)
#include<map>

using namespace std ;

int solution[N][N];

bool isValid(int row,int col,vector<vector<int> > grid,map<pair<int,int> , int> visited){
	if(row >=0 && row<N && col>=0 && col<N && grid[row][col]==0 && visited[make_pair(row,col)]==0)
		return true ;
	return false;
}



void solve_util(vector<vector<int> > grid,int val,pair<int,int> st,pair<int,int> end,map<pair<int,int> , int> visited,int ans[1000][N][N] ,int &size ){
	int i=st.first ;
	int j = st.second ;
	visited[(make_pair(i,j))] = 1;
	if(i==end.first && j==end.second){
			grid[i][j] = val;
			for(int k=0 ; k<N ; k++ ){
    		for(int l=0 ; l<N ; l++)
    			ans[size][k][l] = grid[k][l] ;
    		
		} 
		size++;
		return ;
	}
	grid[i][j] =  -val;
	if(isValid(i-1,j,grid,visited))
		//cout<<i<<" "<<j<<" - top "<<endl,
		solve_util(grid,val,make_pair(i-1,j),end,visited,ans,size) ;
//	else
//		cout<<i<<" "<<j<<": top is invalid"<<endl;
	if(isValid(i+1,j,grid,visited))
		//cout<<i<<" "<<j<<" - bottom "<<endl,
		solve_util(grid,val,make_pair(i+1,j),end,visited,ans,size) ;
//	else
//		cout<<i<<" "<<j<<": bottom is invalid"<<endl;
	if(isValid(i,j-1,grid,visited))
		//cout<<i<<" "<<j<<" - left "<<endl,
		solve_util(grid,val,make_pair(i,j-1),end,visited,ans,size) ;
		//else
		//cout<<i<<" "<<j<<": left is invalid"<<endl;
	if(isValid(i,j+1,grid,visited))
    //	cout<<i<<" "<<j<<" - right "<<endl,
	solve_util(grid,val,make_pair(i,j+1),end,visited,ans,size) ;
    //	else
	//	cout<<i<<" "<<j<<": right is invalid"<<endl;
	
	
	//right
	//bottom
	//down
	return ;
	
}


bool check(vector<vector<int> > grid){
	int i,j ;
	for(i = 0 ; i<N ; i++){
		for(j = 0 ; j<N ; j++)
			if(grid[i][j]==0)
				return false;
	}
	return true;
//	for(i = 1 ; i<=NUM ; i++)
}
bool solve(vector<vector<int> > grid,int n){
//		cout<<"Thinking :)\n";
		if(n > NUM){
			if(check(grid)){
			for(int i=0 ; i<N ; i++){
				for(int j=0 ; j<N ; j++)
					solution[i][j] = grid[i][j];
		
			}
			return true;
			}
			return false;
		}
		pair<int,int> st;
		pair<int,int> ed;
		bool start = false ;
		for(int i=0 ; i<N ; i++){
			for(int j=0 ; j<N ; j++){
				if(grid[i][j]==n){
				if(start==false){
					st = make_pair(i,j);
					start = true;
				}
				else
					ed = make_pair(i,j);
				}
			}
		}
		grid[st.first][st.second] = 0;
		grid[ed.first][ed.second] = 0;
		map< pair<int,int> , int> visited;
		int size = 0;
		int ans[1000][N][N] ;
//		cout<<"hoo";
		solve_util(grid,n,st,ed,visited,ans,size); 
		//cout<<"Solutions : "<<size<<endl;
		for(int i=0 ; i<size ; i++){
				cout<<"\nTrying for : "<<n<<endl;
			//	cout<<"hard"<<endl;
				vector<vector<int> > temp ;
				temp = grid;
				for(int j=0 ; j<N; j++)
				{
					for(int k=0;k<N ; k++)
						grid[j][k]	= ans[i][j][k] ;
					//cout<<endl;
				}
				
				if(solve(grid,n+1))
					return true ;
				grid = temp;
						
		}
		return false;
}

int main(){
	vector<vector<int> > grid;
	cout<<"GRID!!\n";
	for(int i=0 ; i<N ; i++){
		cout<<"Row "<<i+1<<endl;
		vector<int> temp ;
		for(int j=0 ; j<N ; j++){
			int val;
			cin>>val;
			temp.push_back(val);
		}
		grid.push_back(temp);

	}
	/*
	vector<int> temp (N,0) ;
	temp[0] =  4 ;
	grid.push_back(temp);

	vector<int> tp (N,0) ;
	grid.push_back(tp);
	
	vector<int> mp (N,0) ;
	mp[2] =  2 ;
	grid.push_back(mp);
	
	vector<int> ep (N,0) ;
	ep[0] =  3 ;
	ep[1] =  2 ;
	ep[2] = 1;
	ep[4] = 4;
	grid.push_back(ep);
	
	vector<int> t (N,0) ;
	t[0] =  1 ;
	//t[2] =  3 ;
	t[4] =  3 ;
	grid.push_back(t);
	
/*
  grid[0][0] = 0;
  grid[4][1] = 0;
  map<pair<int,int> ,int> visited;
  //cout<<visited[make_pair(1,2)];

	int ans[1000][N][N] ;
	int size = 0;
 	solve_util(grid,1,make_pair(0,0),make_pair(4,1),visited,ans,size); 
 	for(int i=0 ; i<size ; i++){
		cout<<"Solution"<<i+1<<endl;
		for(int j=0 ; j<N ; j++){
			for(int k=0 ; k<N ;k++)
				cout<<ans[i][j][k]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
//	cout<<grid[0][0];*/
	if(solve(grid,1)){
	//	cout<<"hrllo"<<endl;
			for(int k=0 ; k<N ; k++ ){
    		for(int l=0 ; l<N ; l++)
    			cout<<solution[k][l]<<" ";
    		cout<<endl;
    		//cout<<endl;
		}
	}
	else
  	cout<<"No Solution"<<endl;
	
	
	
}
