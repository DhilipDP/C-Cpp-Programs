#include<iostream>
#include<limits.h>
using namespace std ;

struct Point{
	int x ;
	int y ;
};

int A[] = {1,-1,0,0,-1,1,-1,1};
int B[] = {0,0,1,-1,-1,1,1,-1} ;
  
int steps(Point p1,Point p2,int count)
{
	cout<<p1.x<<" "<<p1.y<<endl;
	if(p1.x > p2.x && p1.y > p2.y)
		return INT_MAX;
	if(p1.x == p2.x && p2.y==p1.y)
		return count ;	
	int res = 0;
	for(int i=0 ; i<8 ; i++)
	{
			p1.x = A[i] , p1.y = B[i] ;
			res= min(res,steps(p1,p2,count+1));
	}
	return res;
}

int main()
{
	Point p1 ={1,2} ;
	Point p2 ={2,3} ;
	cout<<steps(p1,p2,0) ;
}
