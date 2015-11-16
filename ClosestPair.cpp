#include<iostream>
#include<stdlib.h>
#include<limits.h>
#include<float.h>
using namespace std;

struct Point{
	int x,y;
};

int compareX(const void * a,const void * b)
{
	Point *p1 = (Point *)a;
	Point *p2 = (Point *)b;
	return (p1->x - p2->x);
}

int compareY(const void * a,const void * b)
{
	Point *p1 = (Point *)a;
	Point *p2 = (Point *)b;
	return (p1->y- p2->y);
}

float dist(Point p1,Point p2)
{
	return( ((p1.x - p2.x ) * (p1.x - p2.x))  - ((p1.y - p2.y)*(p1.y-p2.y)) );
}

float bruteForce(Point p[],int n)
{
	float min = FLT_MAX;
	int i,j;
	for(i=0 ; i<n ; i++){
		for(j=i+1 ; j<n ; j++){
			if(dist(p[i],p[j]) < min)
				min = dist(p[i],p[j]);
		}
	}
	return min;
}

float mini(float x,float y){
	return x<y ? x : y;
}


float stripClosest(Point strip[],int n,int d)
{
	int min = d;
	for(int i=0 ; i<n ;i++){
		for(int j=i+1 ; j<n && (strip[j].y - strip[i].y) ; j++){
			if(dist(strip[j],strip[i]) < min)
				min = dist(strip[j],strip[i]);
		}
	}
	return min;
}
float closest(Point Px[],Point Py[],int n){
	if(n<=3)
		return bruteForce(Px,n);
	int mid = n/2;
	Point midpoint = Px[mid];
	
	Point Pyl[mid+1];
	Point Pyr[mid+1];
	int li=0,ri=0;
	
	for(int i=0 ; i<n ; i++)
	{
		if(Py[i].x < midpoint.x)
  			Pyl[li++]=Py[i];
		else
			Pyr[ri++]=Py[i];
	}
	
	float dl=  closest(Px,Pyl,mid);
	float dr= closest(Px+mid,Pyr,n-mid);
	
float d = mini(dl,dr);
	
	Point strip[n];
	int i,j=0;
	for(i=0 ; i<n ; i++)
	{
		if(abs(Py[i].x - midpoint.x) < d){
			strip[j++]=Py[i];
		}
	}
	return min(d,stripClosest(strip,j,d));
}
float findClosest(Point P[],int n) 
{
	Point Px[n];
	Point Py[n];
	for(int i=0 ; i<n ; i++){
		Px[i]=Py[i]=P[i];
	}
	qsort(Px,n,sizeof(Point),compareX);
	qsort(Py,n,sizeof(Point),compareY);
	return closest(Px,Py,n);
}
int main(){
	Point P[50];
	int n,i;
	cout<<"Number of points:";
	cin>>n;
	cout<<"Enter the points(x,y) : ";
	for(i=0 ; i<n ; i++)
		cin>>P[i].x>>P[i].y;
	cout<<endl<<"Closest distance: "<<findClosest(P,n);
	return 0;
}
