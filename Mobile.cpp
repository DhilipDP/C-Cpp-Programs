#include<iostream>

using namespace std ;



int getCount(int mobile[4][3],int i,int j,int n,int c){
	if(n==1)
		return 1 ;
	int val ;
	if(i>=0 && i<4 && j>=0 && j<3 && mobile[i][j] != -1)
		val = 1;
	
		if(j>0 && mobile[i][j-1] != -1)
			val += getCount(mobile,i,j-1,n-1,c+1);
		if(j<2 && mobile[i][j+1] != -1)
			val += getCount(mobile,i,j+1,n-1,c+1);
		if(i>0 && mobile[i-1][j] != -1)
			val += getCount(mobile,i-1,j,n-1,c+1);
		if(i<3 && mobile[i+1][j] != -1)
			val += getCount(mobile,i+1,j,n-1,c+1);
	
	return val;
}

int number(int mobile[4][3] ,int n){

	int count = 0;
	for(int i=0 ; i<4 ; i++){
		for(int j=0 ; j<3 ; j++){
			if(mobile[i][j]!=-1)
				count += getCount(mobile,i,j,n,0);//cout<<count<<endl;
		}
	}
	//left
	//right
	//up
	//down
	return count;
}

int main(){

	int mobile[4][3] = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
//	cout<<getCount(mobile,0,1,2,0)<<endl<<"prog: "<<endl;
	cout<<number(mobile,3); 
}
