#include<iostream>
#include<stdlib.h>
using namespace std;


int find(int d,int m,int y){

		static int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
		y -= m<3 ;
		return (y + y/4 - y/100 + y/400 + t[m-1] + d)%7;
}


int main()
{
	string s ;
	cin>>s;
	int date = atoi(s.substr(0,2).c_str());
	int month = atoi(s.substr(3,2).c_str());
	int year = atoi(s.substr(6,4).c_str());
		int day = find(date,month,year);		
			switch(day){
				case 0:
				case 7:cout<<"Kiss of Death";
						break;
				case 1: cout<<"Troll Skull";
						break;
				case 2: cout<<"Dragon Fin";
						break;
				case 3: cout<<"Golden Heart";
						break;
				case 4: cout<<"Diamond of the Blood";
						break;
				case 5: cout<<"Chalice of the Phantom";
						break;
				case 6: cout<<"Lock of the Daedra";
						break;
			}
		
}
