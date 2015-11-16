
#include<limits.h>
#include<iostream>
#include<vector>
using namespace std;






void setZeroes(vector<vector<int> > &matrix) {
	//cout<<matrix[0][0];
 	int m=matrix.size();
	 if(m==0)
	 	return ;
	int n=matrix[0].size();
	int hash[n];
	bool rowFlag = false,colFlag = false;
	for(int i=0 ;i<n ; i++){
		if(matrix[0][i]==0){
			rowFlag=true;
			break;
		}
	}
	for(int i=0 ;i<m ; i++){
		if(matrix[i][0]==0){
			colFlag=true;
			break;
		}
	}
	/*
	memset(hash,0,sizeof(hash));
	vector<vector<int> > :: iterator it;
	*/
	int i,j; 
	for(i=0 ; i<m ; i++){
		for(j=0 ; j<n ; j++){
			if(matrix[i][j]==0)
				matrix[0][j] = 0,matrix[i][0]=0;
		}
	}
	for(i=1 ; i<m ; i++)
	{
		for(j=1 ; j<n ; j++){
			if(matrix[0][j]==0 || matrix[i][0] ==0 )
				matrix[i][j]=0;
		}
	}
	if(rowFlag){
		for(j=0 ; j<n ; j++)
			matrix[0][j] = 0;
	}
	if(colFlag){
		for(j=0 ; j<m ; j++)
			matrix[j][0] = 0;
	}
}
    
    int main(){
    	cout<<INT_MAX<<endl;
    	 vector<vector<int> > v;
    	 vector<int> t;
    	 t.push_back(0);
    	 t.push_back(0);
    	 t.push_back(0);
    	 t.push_back(5);
    	 v.push_back(t);
    	 t.clear();
    	 t.push_back(4);
    	 t.push_back(3);
    	 t.push_back(1);
    	 t.push_back(4);
    	  v.push_back(t);
    	 t.clear();
    	 t.push_back(0);
    	 t.push_back(1);
    	 t.push_back(1);
    	 t.push_back(4);
    	 	  v.push_back(t);
    	 t.clear();
    	 t.push_back(1);
    	 t.push_back(2);
    	 t.push_back(1);
    	 t.push_back(3);
    	 	  v.push_back(t);
    	 t.clear();
    	 t.push_back(0);
    	 t.push_back(0);
    	 t.push_back(1);
    	 t.push_back(1);
    	 
    /*	 
    	 for(int i=4 ;i<=6 ; i++)
    	 	t.push_back(i);
    	v.push_back(t);
    	 t.clear();
    	 for(int i=7 ;i<=9 ; i++)
    	 	t.push_back(i);
    	v.push_back(t);
    	  */
		 
    	setZeroes(v);
		vector<vector<int> > :: iterator it;
		for(it = v.begin() ;  it!= v.end() ; it++){
			vector<int> :: iterator i;
			vector<int> t = *it;
			for(i = t.begin() ; i!=t.end() ; i++)
				cout<<*i<<" ";
			cout<<endl;
		
		}
	
	
	}
