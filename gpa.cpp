#include<stdio.h>
#include<iostream>
using namespace std;

int arr[100];

int main(){
	arr['S']=10;
	arr['A']=9;
	arr['B']=8;
	arr['C']=7;
	arr['D']=6;
	arr['E']=5;
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int n;
		scanf("%d",&n);
		int total_credits=0;
		float gpa = 0.0;
		while(n--){
			char grade;
			int credits;
			cin>>credits>>grade;
		//	cout<<grade<<" "<<credits<<endl;
			total_credits += credits ;
			gpa += (arr[grade]*credits);
		}
		printf("%.2f\n",gpa/(float)total_credits);
	}
}
