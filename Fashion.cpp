#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int n;
		scanf("%d",&n);
		int i;
		int men[n+1];
		int women[n+1];
		for(i=0 ; i<n ; i++)
			scanf("%d",&men[i]);
		for(i=0 ; i<n ; i++)
			scanf("%d",&women[i]);
		sort(men,men+n);
		sort(women,women+n);
			int sum=0;
		for(i=0 ; i<n ; i++)
			sum += men[i]*women[i];
		printf("%d\n",sum);
	}
	return 0;
}
