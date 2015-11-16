#include<iostream>
#define R 6
#define C 5
using namespace std ;



void max_size_square(int mat[R][C]){
	int S[R][C] ;
	int i,j ;
	for(i=0 ;i<C ;i++)
		S[0][i] = mat[0][i] ;
	for(i=0 ; i<R ; i++)
		S[i][0] = mat[i][0] ;
	for(i=1 ; i<R ; i++){
		for(j=1 ; j<C ; j++){
			if(mat[i][j] ==0)
				S[i][j] = 0;
			else
				S[i][j] = min(min(S[i][j-1] , S[i-1][j]),S[i-1][j-1]) + 1 ;
		}
	}
	cout<<"S matrxi : "<<endl ;
	for(i=0 ; i<R ; i++){
		for(j=0 ; j<C ; j++)
			cout<<S[i][j]<<" " ;
		cout<<endl;
	}
	cout<<endl ;
	int max_i = 0,max_j =0 , max_val=0 ;
	for(i=0 ; i<R ; i++){
		for(j=0 ; j<C ; j++){
			if(S[i][j] > max_val){
				max_val = S[i][j] ;
				max_i = i;
				max_j = j;
			}
		}
	}
	cout<<"Maximum size square matrix:"<<endl ;
//	cout<<max_i<<" "<<max_j<<" "<<max_val<<endl;
	for(i=max_i - max_val + 1 ; i<=max_i ; i++ )
	{
		for(j=max_j - max_val  +1; j<=max_j ; j++)
			cout<<mat[i][j] <<" ";
		cout<<endl;
	}
}


int main(){

int M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
	max_size_square(M);
	 
}
