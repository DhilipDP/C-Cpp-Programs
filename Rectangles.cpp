#include<stdio.h>
#include<math.h>
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1 ; i<=sqrt(n) ; i++){
		ans += n/i-i+1;
	}
	printf("%d",ans);
}
