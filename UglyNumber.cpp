#include<iostream>

using namespace std ;

int min(int a,int b){
	return a<b ? a : b ;
}

int min(int a,int b,int c){
	return min(a,min(b,c));
}
int  findUgly(int n){
	int ugly[n+1];
	ugly[0]=1 ;
	int i2 =0 ,i3 =0 ,i5 = 0 ;
	int next_2 = ugly[i2]*2 ;
	int next_3 = ugly[i3]*3 ;
	int next_5 = ugly[i5]*5 ;
	int next_ugly;
	for(int i= 1 ;i <= n  ;i ++){
		next_ugly = min(next_2,next_3,next_5);
		ugly[i] =  next_ugly;
		if(next_ugly == next_2){
			i2++;
			next_2 = ugly[i2]*2;
		}
		if(next_ugly == next_3){
			i3++;
			next_3 = ugly[i3]*2 ;
		}
		if(next_ugly==next_5){
			i5++;
			next_5 = ugly[i5]*5 ;
		}
	}
	return ugly[n];
}
int main(){
	int n=150 ;
	for(int i=1 ; i<=n  ; i++)
	cout<<findUgly(i-1)<<endl;
}
