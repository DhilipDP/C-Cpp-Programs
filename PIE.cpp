#include<iostream>
#include<float.h>
#include<stdio.h>
using namespace std;

int main(){
	
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int n,f;
		scanf("%d%d",&n,&f);
		int r;
		float totalVolume = 0.0000;
		for(int i=0 ; i<n ; i++){
			scanf("%d",&r);
			 totalVolume +=  (3.14159265358979323846264338327950 * (r*r));
		
	}
		printf("%4lf\n",(totalVolume/(n+1)));
}
}
