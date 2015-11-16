#include<iostream>
//#include<graphics.h>
#include<windows.h>
using namespace std ;

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
int main()
{
	int i,j;
	int x=10,y=10;
	//gotoxy(28,15);
	for(i=1;i<=5;i++){
	//	x++;
	for(j=1;j<=5;j++){
		gotoxy(x,y);
		y++;
		if(i==3 || j==1 || j==5)
		 cout<<"h";//,	cout<<x<<" "<<y<<" "<<"H";
		else
			cout<<" ";//cout<<x<<" "<<y<<" "<<" ";
	
	}
		cout<<endl;
	}
	
//	cout<<"Happy";
}


