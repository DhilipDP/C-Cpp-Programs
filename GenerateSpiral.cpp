#include<iostream>
#include<vector>
using namespace std ;

  vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res ;
        if(n==0)
        	return res ;
        int mat[n][n] ;
        int num = 1,i;
        int fr =0, fc= 0, lr =n-1, lc = n-1 ; 
        while(fr <= lr && fc<=lc){
        //	cout<<"hi";
        	for(i=fc ; i<=lc ; i++)
        		mat[fr][i] = num++;
        	fr++;
			
			for(i=fr ; i<=lr ; i++)
				mat[i][lc] = num++;
			lc--;
			
			if(fr < lr){
			for(i=lc ; i>=fc ; i--)
				mat[lr][i] = num++ ;
			lr--;
			}
			
			if(fc < lc){
				for(i=lr ; i>=fr ; i--)
				mat[i][fc] = num++;
				fc++;
			}
        	
		}
		
		for(i = 0 ; i<n ; i++){
			vector<int> temp ;
			for(int j=0 ; j<n ; j++)
				temp.push_back(mat[i][j]);
			res.push_back(temp);
		} 
		
		return res ;
    }
int main(){
	vector<vector<int> > matrix = generateMatrix(7);
	vector<vector<int> > :: iterator it ;
	vector<int> :: iterator i ;
	for(it = matrix.begin() ; it!= matrix.end() ; it++){
		vector<int> v = *it ;
		for(i = v.begin() ; i!=v.end() ; i++)
			cout<<*i<<" ";
		cout<<endl;
	}
	
}
