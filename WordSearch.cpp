#include<iostream>
#include<vector>
using namespace std ;


int n,r;
string word;


bool find(vector<vector<char> > &board,int i,int j,string ans,int index,vector<vector<bool> > &hash){
	
	cout<<"in find" <<i<<" "<<j<<" "<<ans<<" "<<word<<" "<<index<<" "<<r<<endl; 
	if(index==n-1){
		if(ans==word)
			return true;
		return false;
	}
	index++;
	if(i<r-1 && board[i+1][j]==word[index] && hash[i+1][j] == 0 ){
		hash[i+1][j]=1;
		if(find(board,i+1,j,ans+word[index],index,hash))
			return true ;
		hash[i+1][j] = 0;
	}
	if(j<board[i].size()-1 && board[i][j+1]==word[index] && hash[i][j+1]==0){
		hash[i][j+1]=1;
		if(find(board,i,j+1,ans+word[index],index,hash))
			return true ;
		hash[i][j+1] = 0; 
	}
	if(i>0 && board[i-1][j]==word[index]  && hash[i-1][j]==0){
		hash[i-1][j] = 1;//hash[i-1][j]=1;
		if(find(board,i-1,j,ans+word[index],index,hash))
			return true;
		hash[i-1][j] = 0;
	}
	if(j>0 && board[i][j-1]==word[index] && hash[i][j-1]==0){
		hash[i][j-1] = true;//hash[i][j-1]=1;
		if(find(board,i,j-1,ans+word[index],index,hash))
			return true ;
		hash[i][j-1] = false ;
	}

	return false;
	
	

}
/*   bool exist(vector<vector<char> > &board, string w) {
   		word = w;
         n=word.length();
        if(n==0)
        	return false;
        int index = 0;
        r = board.size();
		int c = board[0].size();
      
        		
        for(int i=0 ; i<r ; i++){

        	for(int j=0 ; j<c ; j++){
        		if(board[i][j]==word[0]){
        		//	cout<<i<<" "<<j<<endl;
        			vector<vector<bool> > hash (board.size() , vector<bool> (board[0].size(),false));
        			hash[i][j] = 1;
        			string ans="";
        			ans+= board[i][j];
        			if(find(board,i,j,ans,index,hash)){
						return true;
					}
				}
			
			}
		
		}
		return false;
    }
    
    */
    bool dfs(vector<vector<char> > &board,int index,int i,int j,string word,vector<vector<bool> > &hash){
    	if(index==word.size())
    		return true ;
    	if(i <0 || i >= board.size() || j<0 || j>=board[0].size())
    		return false ;
    	if(word[index]!=board[i][j] || hash[i][j] == true)
    		return false ;
    	hash[i][j] = true ;
    	if(dfs(board,index+1,i,j+1,word,hash) || dfs(board,index+1,i,j-1,word,hash) || dfs(board,index+1,i+1,j,word,hash) || dfs(board,index+1,i-1,j,word,hash) )
    		return true ;
    	hash[i][j] = false ;
    	return false ;
	}
    
    bool exist(vector<vector<char> > &board,string word){
    	if(board.size()==0)
    		return false ;
    	vector<vector<bool> > hash (board.size() , vector<bool> (board[0].size(),false));
    	for(int i=0 ; i<board.size() ; i++){
    		for(int j=0 ; j<board[0].size() ; j++){
    				
    				if(dfs(board,0,i,j,word,hash))
    					return true;
			}
		}
		return false ;
    }
int  main(){
	
	vector<vector<char> > v;
	vector<char> c;
	c.push_back('A');c.push_back('A');//c.push_back('C');c.push_back('E');
	v.push_back(c);
/*	c.clear();
		c.push_back('S');c.push_back('F');c.push_back('E');c.push_back('S');
	v.push_back(c);
	c.clear();
		c.push_back('A');c.push_back('D');c.push_back('E');c.push_back('E');
	v.push_back(c);
	c.clear();*/
	cout<<exist(v,"AAA");

}
