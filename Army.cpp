#include<stdio.h>

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int NG,NM;
		scanf("%d%d",&NG,&NM);
		int max1=0,max2=0;
		for(int i=0 ; i<NG ; i++){
			int val;
			scanf("%d",&val);
			if(val > max1)
				max1 = val;
		}
		for(int i=0 ; i<NM ; i++){
			int val;
			scanf("%d",&val);
			if(val > max2)
				max2 = val;
		}
		if(max1>=max2)
			printf("Godzilla\n");
		else
			printf("MechaGodzilla\n");
	}
	return 0;
}
