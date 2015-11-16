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
			 totalVolume +=  (3.14 * (r*r));
			 cout<<totalVolume<<endl;
		
	}
		printf("%4lf\n",(totalVolume/(n+1)));
	cout<<endl<<(totalVolume/(n+1) ) * (n+1);
}
}
