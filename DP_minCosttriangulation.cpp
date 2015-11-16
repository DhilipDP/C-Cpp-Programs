#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std ;


struct Point{
	int x,y;
};



double dist(Point p1,Point p2){
	return sqrt(((p1.x - p2.x)*(p1.x-p2.x)) + ((p1.y-p2.y)*(p1.y-p2.y))) ;
}

double cost(Point p[],int i,int j,int k ){
	
	return dist(p[i],p[j]) + dist(p[j],p[k]) + dist(p[k],p[i]) ;
}

double minCostTriangulation(Point p[],int i,int j){
	if(j-i < 2)
		return 0.0 ;
	double ret = 1000000.00;
	for(int k=i+1 ; k<=j-1 ; k++)
	{
		ret = min(ret,minCostTriangulation(p,i,k) + minCostTriangulation(p,k,j) + cost(p,i,k,j));
	//	cout<<ret<<" "<<i<<" "<<k<<" "<<j<<endl;
	}
	return ret ;
}


double mct(Point p[] ,int n){
	double tab[n][n] ;
	int i,j,k,l ;
	for(l=1 ; l<=n ; l++){
		cout<<l<<endl;
		for(i=0 ; i<=n-l ; i++){
			cout<<i<<" " ;
			j = i+l-1 ;
			cout<<j<<" ";
			if(j-i < 2)
				tab[i][j] = 0.0 ;
			else
			{
				tab[i][j] = 100000.00 ;
				for(k=i+1 ; k<=j-1 ; k++)
					tab[i][j] = min(tab[i][j],tab[i][k] + tab[k][j] + cost(p,i,k,j) );
			}
			cout<<tab[i][j]<<endl;
		}
	}
	return tab[0][n-1] ;
}


int main() 
{
	Point p[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
	int n = sizeof(p)/sizeof(p[0]);
	cout<<minCostTriangulation(p,0,n-1);
	cout<<endl<<mct(p,n);
}
