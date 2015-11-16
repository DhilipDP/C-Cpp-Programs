#include<iostream>
#include<algorithm>
using namespace std;

bool checkZero(string number){
	bool flag = false;
	for(int i=0 ; number[i] ; i++)
	{
		if(number[i]-'0'!=0){
			flag=true;
			break;
		}
	}
	return flag;
}

string convert(string number){
	string ones[]={"","one","two","three","four","five","six","seven","eight","nine"};
	string tentwenty[]={"","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
	string tens[]={"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	int len = number.size();
	string output="";
	int i=0,val;
	while(len){
		switch(len){
			case 4 :output +=convert(number.substr(0,1)) + "thousand ";
					len--;
					i=1;
					break;
			case 5 : output +=convert(number.substr(0,2)) + "thousand ";
					 len-=2;
					 i=2;
					break;
			case 3 :    val = number[i++]-'0' ;
					   output += (ones[val]);
					  if(val!=0)
							output +=  " hundred ";
						len--;
						break;
			case 2 : 
					if(number[i]-'0'==0)
						{
							i++;
							len--;
							break;
						}
					if(number[i]-'0'==1 && ( number[i+1] - '0' >= 1 && number[i+1]-'0' <= 9)){
					int j=i+1;
						output += (tentwenty[number[j++]-'0']+" ");
						len-=2;
						break;
					}
		        	output += (tens[number[i++]-'0']+" ");
		        //	cout<<output<<endl;
						len--;
						break;
			case 1 : output += ( ones[number[i++]-'0']+" ");
						len--;
		} 
	}
	return output;
	
}


string convertintowords(string number){
	    if(number=="")
	    	return "Zero" ;
		if(checkZero(number))
		   return convert(number);
       	else
		    return "Zero ";
}
int main(){
	string number;
	cin>>number;
	cout<<convertintowords(number);
/*	cout<<"Enter an amount less than 99999.99/-: ";
	cin>>number;
	string rupee="",paise="",output="";
	int i;
	for( i=0 ; number[i] ; i++){
		if(number[i]!='.'){
			rupee+=number[i];
		}
		else
			break;
	}
	if(i!= number.length())
		paise = number.substr(i+1,number.length()-i);
    output += convertintowords(rupee) + " rupees and " + convertintowords(paise) + " paise only";
    cout<<endl<<output;
*/
	
}
