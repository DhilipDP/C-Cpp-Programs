#include<stdio.h>
#include<iostream>
using namespace std;

int maxi(int a,int b){
	return a>b ? a : b;
}

int maxi(int a,int b,int c){
	return a > b ? (a > c ? a : c) : (b > c ? b : c) ;
}

int survive(int H,int A,int mode,int t)
{
//cout<<H<<" "<<A<<" "<<mode<<" "<<t<<endl;
	if(H<=0 || A<=0)
		return t;
	if(mode==1){
		int val = t;
		t ++;
		H += 3;
		A += 2;
		return maxi(survive(H,A,2,t),survive(H,A,3,t));
	}
		if(mode==2){
		t ++;
		H -= 5;
		A -= 10;
		if(H<=0 || A<=0)
			return --t;
		return maxi(survive(H,A,1,t),survive(H,A,3,t));
	}
	if(mode==3){
		t ++;
		H -= 20;
		A += 5;
		if(H<=0 || A<=0)
			return --t;
		return maxi(survive(H,A,1,t),survive(H,A,2,t));
	}
//	return t;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int H,A;
		scanf("%d%d",&H,&A);
//		cout<<"2 returns: "<<survive(H,A,2,0)<<endl;
		printf("%d\n",maxi(survive(H,A,1,0),survive(H,A,2,0),survive(H,A,3,0)));
	}
}
