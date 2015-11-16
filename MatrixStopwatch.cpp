#include<iostream>
#include<stdlib.h>

using namespace std ;


void print(int mat[10][10]){
	for(int i=0 ; i<10 ; i++){
		for(int j=0 ; j<10 ; j++)
			cout<<mat[i][j] <<" ";
		cout<<endl;
	}
}
int main(){
	int mat[10][10] = {0};
	int table[101] = {0};
	int i,j;
	for(i=0 ; i<10 ; i++)
	{
		int random = rand()%100+1;
		if(table[random]==0){
				table[random]==1;
				mat[0][i] = random ;
		}
	}
	for(i=0 ; i<10 ; i++)
	{
		int random = rand()%100+1;
		if(table[random]==0){
				table[random]==1;
				mat[i][0] = random ;
		}
	}
	print(mat);
}
	
