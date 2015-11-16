#include<iostream>

using namespace std ;

bool search(char mat[3][3],int i,int j,int r,int c,string s,string ans){
	cout<<"Searching : "<<i<<" "<<j<<endl;
	if(i>=r || j>=c ||  i < 0 || j<0)
	{
		cout<<"Break"<<endl;
		if(s==ans)
			return true ;
		return false ;
	}
	ans += mat[i][j];
	return search(mat,i+1,j,r,c,s,ans) || search(mat,i-1,j,r,c,s,ans) || search(mat,i,j+1,r,c,s,ans) || search(mat,i,j-1,r,c,s,ans);
	
}

void findString(char mat[3][3],int r,int c,string s){
	if(s.length() > r && s.length() > c)
	{
		cout<<"Not possible\n";
		return ;
	}
	//int st_row = 0,st_col=0;
	int i,j;
	bool found = false;
	for(i=0 ; i<r ; i++){
		for(j=0 ; j<c ; j++){
			if(mat[i][j]==s[0]){
				string ans="";
				if(search(mat,i,j,r,c,s,ans))
				{
					cout<<"Found at: "<<i<<" "<<j<<endl;
					found = true;
					break;
				}
			}
		}
	}
	if(!found){
		cout<<"not found"<<endl;
	}
	
}
int main(){
	char mat[3][3] = {{'d','a','b'},
					 {'o','b','r'},
					 {'g','o','n'}};
	findString(mat,3,3,"god");
					 
					  
						
}
