#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

bool isPrime(int num)
{
	if(num==2 || num==3)
		return true;
	if(num % 2 ==0)
		return false;
	if(num%3==0)
		return false;
	int i=5 ,w=2;
	while(i*i <= num){
		if(num % i==0)
			return false;
		i += w;
		w = 6 - w;
	}
	return true;
}
bool check(int num){
		if(num==2)
			return true;
		if(num==1 || isPrime(num) )
			return false;
		int sum = 0;
		for(int i=1 ; i<=sqrt(num) ; i++){
			if(num % i==0)
				{
					sum += i;
					if(i!=(num/i))
						sum += (num/i);
				}
		}
			return isPrime(sum);
	}



int main(){
//	cout<<(262144 & 262143);
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int a,b;
		scanf("%d%d",&a,&b);
		int count = 0;
		for(int i=a ; i<=b ; i++)
			if( check(i)){
		//		cout<<i<<endl;
				count++;
			}
		printf("%d\n",count);
	}
}
