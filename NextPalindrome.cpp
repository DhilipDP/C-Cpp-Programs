#include<iostream>
#include<string.h>

using namespace std;

bool areAllnine(string num,int n){
	for(int i=0 ; num[i] ; i++){
		if((num[i]-'0')!=9)
			return false;
	}
	return true;
}


void generateNext(string num,int n)
{

	int mid = n/2;
	int i= mid-1;
	int j= (n%2) ? mid+1 :mid;
	bool leftsmaller = false;
	while(i>=0 && num[i]==num[j]){
		i--;	
		j++;
	}
	if(i<0 || (num[i]-'0' < num[j]-'0'))
		leftsmaller = true;
	while(i>=0){
		num[j++]=num[i--];		
	}
	if(leftsmaller){
		int carry=1;
		i = mid -1;
		if(n%2){
			
			num[mid]=((long int)(num[mid]-'0')+carry)+'0';
			carry = (long int)(num[mid]-'0')/10;
			num[mid]=((long int)(num[mid]-'0')%10)+'0';
			j=mid+1;
		}
		else
			j=mid;
		while(i>=0){
				num[i]=((long int)(num[i]-'0')+carry)+'0';
			carry = (long int)(num[i]-'0')/10;
			num[i]=((long int)(num[i]-'0')%10)+'0';
			num[j++]=num[i--];
		}
	}
	for(int k=0 ; num[k] ; k++)
			cout<<num[k]-'0';
		cout<<endl;
}


void generatePalindrome(string num,int n){
	if(areAllnine(num,n)){
		cout<<"1";
		for(int i=1 ; i<n ; i++)
			cout<<"0";
		cout<<"1"<<endl;
	}
	else{
		generateNext(num,n);

	}
	
}
int main(){
	long int tests;
	cin>>tests;
	while(tests--){
		string number;
		cin>>number;
		generatePalindrome(number,number.size());
	}
}
