#include<iostream>

using namespace std; 

int num_of_days(int month)
{
	if(month==2)
		return 28;
	if(month <= 7)
		return (month & 1) ? 31 : 30 ;
	return (month & 1) ? 30 : 31;
}

void generate_t(int t[])
{
	t[0] = 0;
	int sum = 0 ;
	for(int i=1 ; i<12 ; i++){
		int no_days = num_of_days(i) ;
	//	cout<<sum<<" "<<no_days<<endl;
		t[i] = (sum + no_days)%7;
		sum += no_days ;
		if(i >= 2)
			t[i]--;
		if(t[i] < 0)
			t[i] += 7;
	}
}

int Day(int date, int month, int year)
{
	int t[12] ;
	generate_t(t) ;	
	if( month < 3)
		year--;
	return (year + year/4 - year/100 + year/400 + t[month-1] + date)%7;
}

int main()
{
	cout<<Day(28,6,2015) ;
}
