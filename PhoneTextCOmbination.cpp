#include<iostream>
using namespace std;


char phone[10][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void printCombination(int numbers[],int cur_dig ,char result[],int n){
	if(cur_dig == n){
		cout<<result<<endl;
		return  ;
	}
	for(int i=0 ; i<strlen(phone[numbers[cur_dig]]) ; i++){
		result[cur_dig] = phone[numbers[cur_dig]][i];
		printCombination(numbers,cur_dig+1,result,n);
		if(numbers[cur_dig]==0 || numbers[cur_dig]==1)
			return ;
	}
	
}
int main(){
	int n,i;
	int numbers[10];
	cout<<"\nEnter number of digits: ";
	cin>>n;
	cout<<"Enter :\n";
	for(i=0 ; i<n ; i++)
		cin>>numbers[i];
	char result[n+1];
	result[n]='\0';
	printCombination(numbers,0,result,n);
}
