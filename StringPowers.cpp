#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		string a , b;
		cin>>a>>b;
		if(a==b)
			printf("YES\n");
		else if(a.length()==b.length())
			printf("NO\n");
		else{
			string big,small,temp;
			int biglen,smalllen;
			int len1 = a.length();
			int len2 = b.length();
			if(len1 > len2){
				big = a;
			   small = b;
			   biglen = len1;
			   smalllen = len2;
			}else{
				big = b;
				small = a;
				biglen = len2;
				smalllen = len1;
			}
			if(biglen % smalllen != 0)
				printf("NO\n");
			else{
				
				temp = small;
				int val = biglen / smalllen ;
				val--;
				while(val--){
					small += temp;
				}
				if(small== big)
					printf("YES\n");
				else
					printf("NO\n");
			}	
		}
			
	}	
}

