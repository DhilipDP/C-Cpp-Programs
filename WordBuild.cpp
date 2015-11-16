#include<iostream>
#include<vector>
using namespace std ;


int n,m;
int st,ed;
string dir;


    bool dfs(vector<vector<char> > &board,int index,int i,int j,string word,vector<vector<bool> > &hash){
    	if(index==word.size())
    		return true ;
    	if(i <0 || i >= board.size() || j<0 || j>=board[0].size())
    		return false ;
    	if(word[index]!=board[i][j] || hash[i][j] == true)
    		return false ;
    //	cout<<i<<" "<<j<<endl;
    	hash[i][j] = true ;
    	if(dfs(board,index+1,i,j+1,word,hash) || dfs(board,index+1,i,j-1,word,hash) || dfs(board,index+1,i+1,j,word,hash) || dfs(board,index+1,i-1,j,word,hash) || dfs(board,index+1,i-1,j-1,word,hash) || dfs(board,index+1,i-1,j+1,word,hash) || dfs(board,index+1,i+1,j-1,word,hash )|| dfs(board,index+1,i+1,j+1,word,hash))
    		return true ;
    	hash[i][j] = false ;
    	return false ;
	}
    
    bool exist(vector<vector<char> > &board,string word){
    	if(board.size()==0)
    		return false ;
    	vector<vector<bool> > hash (board.size() , vector<bool> (board[0].size(),false));
    	int r,c ;
    	for(int i=0 ; i<board.size() ; i++){
    		for(int j=0 ; j<board[0].size() ; j++){
    				if(board[i][j] == word[0])
    				{r=i;c=j;}
    				if(dfs(board,0,i,j,word,hash)){
    					st = i;
    					ed = j;
						return true;
    				}
			}
		}
		return false ;
    }
    bool valid(int i,int j,vector<vector<bool> > visited){
    		if(i <0 || i >= n || j<0 || j>=m || visited[i][j] == true )
    		return false ;
    		return true;
	}
    
    string getDirection(vector<vector<char> > board,string word,int i,int j,string s,vector<vector<bool> > visited){
    	
    	if(word.length()==1)
    		return s;
    	visited[i][j] = true;
    	string temp = s;
    	int  c= 0;
    	if(valid(i-1,j,visited) && board[i-1][j] == word[1]){
    		if(i==st && j==ed)
    		  	s = "N",c++;
    		getDirection(board,word.substr(1,word.length()-1),i-1,j,s,visited);
    	}
    	if(valid(i+1,j,visited) && board[i+1][j] == word[1]){
    		if(i==st && j==ed)
			s = "S",c++;
    		getDirection(board,word.substr(1,word.length()-1),i+1,j,s,visited);
    	}
		if(valid(i,j+1,visited) && board[i][j+1] == word[1]){
				if(i==st && j==ed)
    				s = "E",c++;
    	    getDirection(board,word.substr(1,word.length()-1),i,j+1,s,visited);
    	}
    	if(valid(i,j-1,visited) && board[i][j-1] == word[1]){
    			if(i==st && j==ed)
    				s = "W",c++;
    		getDirection(board,word.substr(1,word.length()-1),i,j-1,s,visited);
    	}
    	if(valid(i-1,j-1,visited) && board[i-1][j-1] == word[1]){
    		if(i==st && j==ed)
    		s = "NW",c++;
    	    getDirection(board,word.substr(1,word.length()-1),i-1,j-1,s,visited);
    	}
    	if(valid(i-1,j+1,visited) && board[i-1][j+1] == word[1]){
    		if(i==st && j==ed)
    		s = "NE",c++;
    		getDirection(board,word.substr(1,word.length()-1),i-1,j+1,s,visited);
    	}
    	if(valid(i+1,j-1,visited) && board[i+1][j-1] == word[1]){
    		if(i==st && j==ed)
    		s = "SW",c++;
    		getDirection(board,word.substr(1,word.length()-1),i+1,j-1,s,visited);
    	}
    	if(valid(i+1,j+1,visited) && board[i+1][j+1] == word[1]){
    		if(i==st && j==ed)
    		s = "SE",c++;
    		getDirection(board,word.substr(1,word.length()-1),i+1,j+1,s,visited);
    	}
    	if(c==1){
    		if(i==st&& j==ed)
    			return s;
    		return temp;
    		
    		
		}
	}
int  main(){
	
	cin>>n>>m;
	vector<vector<char> > board (n, vector<char>(m,'.'));
	for(int i=0 ; i<n ; i++){
		string s ;
		cin>>s ;
		for(int j=0 ; j<m ; j++)
			s[j] = toupper(s[j]) ,board[i][j] = s[j];
	}
	int l;
	cin>>l;
	while(l--){
		int r=0,c=0;
		string dir;
		string word;
		cin>>word;
		for(int i=0 ; i<word.length() ; i++)
			word[i] = toupper(word[i]);
		st=0;
		ed=0;
		string d;
		if(exist(board,word)){
		//	cout<<"yes!";
		//	cout<<st<<" "<<ed;
			vector<vector<bool> > visited(n,vector<bool> (m,false));
			cout<<word<<"("<<st+1<<","<<ed+1<<","<<getDirection(board,word,st,ed,d,visited)<<")"<<endl;
		//	cout<<
		}
		//else
		//	cout<<"no";
	}

}
