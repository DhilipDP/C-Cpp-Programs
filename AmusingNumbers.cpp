#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>

using namespace std;

string convert(long long int num){
	string bin="";
	long long int quo=num , rem;
	if(num==0)
		return "0";
	while(quo!=0){
		rem = quo % 2;
		quo /= 2;
		bin.push_back(rem + '0');
	}
	reverse(bin.begin(),bin.end());
	return bin;
}
int main(){
//	cout<<convert(2);
	int tests;
	scanf("%d",&tests);
	while(tests--){
		long long int number,temp,n=1,sum=0,pre_sum,pos;
		scanf("%lld",&number);
		temp = number;
		if(	number==1 )
			 printf("5\n") ;
		else if(number==2)
			 printf("6\n");
		else{
		while(sum < temp){
			pre_sum = sum;
			sum += pow(2,n);
			if(sum < temp)
				n++;
		}
		pos = number - pre_sum;
	//	cout<<n<<" "<<pos<<endl;
		string bin = convert(pos-1);
		long long int no = n-bin.length();
		if(bin.length() < n){
			for(long long int i=0 ; i < no ; i++){
				bin = "0" + bin;
			}
		}
	//	cout<<bin;
		for(long long int i=0 ; bin[i] ; i++){
			bin[i]=='0' ? bin[i]='5' : bin[i]='6';
		}
		cout<<bin<<endl;
		
	}	
	}
}
