#include<iostream>

using namespace std ;


void printAllClusters(int mat[2][2],int rowpos,int colpos,string cluster,bool visited[2][2],int r,int c){

	if((rowpos < 0 || rowpos >= r || colpos < 0 || colpos >= c) || mat[rowpos][colpos]==0)// || visited[rowpos][colpos]){
		cout<<rowpos<<" "<<colpos<<endl;
		cout<<cluster<<endl;
		return ;
	}
//	visited[rowpos][colpos] = 1;
	cluster += "1";
	printAllClusters(mat,rowpos+1,colpos,cluster,visited,r,c);
	printAllClusters(mat,rowpos-1,colpos,cluster,visited,r,c);
	printAllClusters(mat,rowpos,colpos+1,cluster,visited,r,c);
	printAllClusters(mat,rowpos,colpos-1,cluster,visited,r,c);
	printAllClusters(mat,rowpos+1,colpos-1,cluster,visited,r,c);
	printAllClusters(mat,rowpos-1,colpos+1,cluster,visited,r,c);
	printAllClusters(mat,rowpos+1,colpos+1,cluster,visited,r,c);
	printAllClusters(mat,rowpos-11,colpos-1,cluster,visited,r,c);
	
}
int main(){
	int mat[2][2] = {1,0,1,1};//,1,0,0,1,1};
	string cluster = "";
	bool visited[2][2] = {0};
	printAllClusters(mat,1,0,cluster,visited,2,2);
}
