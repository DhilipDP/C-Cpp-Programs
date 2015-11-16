#include<iostream>

using namespace std ;

int main()
{
	static int i=5;
	if(--i)
	{
		cout<<i<<endl;
		main();
	}
}
