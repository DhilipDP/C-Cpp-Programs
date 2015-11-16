#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

int value(char num){
	switch(num){
		case 'A' : return 10;
		case 'B' : return 11;
		case 'C' : return 12;
		case 'D' : return 13;
		case 'E' : return 14;
		case 'F' : return 15;
		default : return num-'0';
	}
}

char v(int num){
	switch(num){
	case 10 : return 'A';
	case 11 : return 'B' ;
	case 12 : return 'C';
	case 13 : return 'D';
	case 14 : return 'E';
	case 15 : return 'F';
	default : return num+'0';
	}
}

long int to_decimal(int base,string number){
	if(base==10)
		return atol(number.c_str());
	long int deci = 0;
	reverse(number.begin(),number.end());
	for(int i=0 ; number[i] ; i++){
		if(number[i]-'0'!=0){
			int val = value(number[i]);
			deci +=( val *pow(base,i) );
		}
	}
	return deci;
}

string from_decimal(int base,long int number){
	if(base==10){
		
	}
	string ans = "";
	long int quo=number,rem;
	while(quo!=0){
		rem = quo % base;
		quo = quo/base ;
		ans.push_back(v(rem));
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	int from,to;
	string number;
	while(cin>>number>>from>>to){
		long int deci;
		string ans;
		deci = to_decimal(from,number);
		if(to==10){
			//cout<<deci<<endl;
			long int temp = deci;
			int count=0;
			while(temp > 0){
				temp /= 10;
				count++;
			}			
			for(int i=0 ; i<(7-count) ; i++)
				cout<<" ";
			cout<<deci<<endl;
		}
		else{
			ans = from_decimal(to,deci);
			if(ans.length()>7)
				cout<<"  ERROR\n";
			else{
				int len = ans.length();
				for(int i=0 ; i<(7-len) ; i++)
					ans = ' ' + ans;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
