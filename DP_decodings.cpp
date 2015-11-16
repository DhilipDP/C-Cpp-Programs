#include<iostream>

using namespace std ;


int countDecoding(string digits, int n)
{
    // base cases
    if (n == 0 || n == 1)
        return 1;
 
    int count = 0;  // Initialize count
 
    // If the last digit is not 0, then last digit must add to
    // the number of words
    if (digits[n-1] > '0')
        count =  countDecoding(digits, n-1);
 
    // If the last two digits form a number smaller than or equal to 26,
    // then consider last two digits and recur
    if (digits[n-2] < '2' || (digits[n-2] == '2' && digits[n-1] < '7') )
        count +=  countDecoding(digits, n-2);
 
    return count;
}


int decodings(string digit ,int n){
//	cout<<n<<endl;
	if(n==1)
		return 1 ;
	int count = 0;
	if((digit[n-2]=='1' ) || (digit[n-2] == '2' && digit[n-1] <= '6'))
		count += (decodings(digit,n-1)+1);
	else
		count += decodings(digit,n-1);
//	cout<<"Returning : "<<count<<endl;
	return count ;
}

int main(){
	string digit = "1111111111" ;
	cout<<decodings(digit,digit.length());
	cout<<endl<<countDecoding(digit,digit.length());
}
