#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std ;


class Test{
static	int s ;	
};
class Sample{
	public :
		int x ,y;
		Sample(){
			cout<<"Default" <<endl ;
		}
		
		Sample( const Sample  &a){
			x = a.x ;
			y = a.y ;
			cout<<"Copy constructor executed"<<endl;
		}
		
};

void fun(Sample s)
{
	//
}

Sample test()
{
	Sample s ;
	cout<<"not yet"<<endl;
	return s ;
}

Test te ;
int main()
{
	Test te;
	
	cout<<sizeof(::te)<<endl;
	int c=1 ;
//	while(1){
//		malloc(1024*1024) ;
//		cout<<c++<<" ";
//	}
	char  sp[] = "Nandu" ;
	cout<<strlen(sp) <<endl;
	char str[] ="" ;
	printf("%d ",sizeof(str)) ;
	string st = "Nanduvinodwerfwoejrpo3jrpo32jpo3j4po2jpoj32jp" ;
	cout<<sizeof(st)<<endl ;
	cout<<sizeof(Test) ;
	Sample s ;
	Sample t = s ,r;
	r = s ;
	Sample q(r) ;
	fun(q) ;
	r = test();
}
