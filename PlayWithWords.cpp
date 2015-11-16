#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		long int n;
		scanf("%ld",&n);
		string str[100000];
		bool flag = true;
		if(n==1)
			flag=false;
		for(long int i=0 ; i<n ; i++){
			cin>>str[i];
			if(i>0 && flag) {
				if(str[i][0] !=str[i-1][str[i-1].length()-1])
					flag = false;
			}
		}
		if(flag)
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
	}
	return 0;
}
