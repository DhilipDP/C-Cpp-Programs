#include<iostream>
using namespace std ;
unsigned int reverseBits(unsigned int num)
{
    unsigned int count = 6;
    unsigned int reverse_num = num;
    
    num >>= 1; 
    cout<<num<<endl;
    while(num)
    {
       reverse_num <<= 1;       
       reverse_num |= num & 1;
       num >>= 1;
       count--;
       cout<<reverse_num<<endl;
    }
    reverse_num <<= count;
    cout<<reverse_num<<endl;
	return reverse_num;
    
}

int main()
{
	int v=3 ;
	for(int i=0 ; i<=7 ; i++)
		cout<<((v & (1<<i))!=0) ? "1" : "0";
	
	cout<<endl;
	 v = v>>1 ;
		for(int i=0 ; i<=7 ; i++)
		cout<<((v & (1<<i))!=0) ? "1" : "0";
cout<<endl;
	 
	int mask = v >> 7 ;
	cout<<endl;
	for(int i=0 ; i<=7 ; i++)
		cout<<((mask & (1<<i))!=0) ? "1" : "0";
	
	cout<<endl;
	cout<<(v << 31) ;

	unsigned int num = 5; 
	
	unsigned int rev = num ;
	int count = 7;
	num>>=1;
	while(num  > 0)
	{
		cout<<rev<<" "<<num<<endl;
		rev <<= 1 ;
		rev |= num & 1;
		num >>=1;
		count--;
		cout<<rev<<" "<<num<<endl;
	}
	cout<<rev<<endl;
	rev <<= count ;
	cout<<rev<<endl;
	
	cout<<reverseBits(5);
}

