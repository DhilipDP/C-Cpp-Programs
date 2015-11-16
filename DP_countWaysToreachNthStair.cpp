#include<iostream>

using namespace std ;


int _count(int s,int m){
	if(s<=1)
		return s;
	int i,j;
	int val =0;
	for(i=1 ; i<=m  && i<=s ; i++)
		val += _count(s-i,m);
	return val;

}

int countWays(int s,int m){
	return _count(s+1,m);
}


int count_Dp(int s,int m){
	int res[s+1];
	res[0] = res[1] = 1 ;
	int i,j;
	for(i=2 ; i<=s ; i++){
		res[i] = 0; 
		for(j=1 ; j<=i && j<=m; j++)
			res[i] += res[i-j];
	}
	return res[s];
}	


int main(){

	int s = 4;
	int m= 3 ;
	cout<<countWays(s,m);
	cout<<endl<<count_Dp(s,m);
}
