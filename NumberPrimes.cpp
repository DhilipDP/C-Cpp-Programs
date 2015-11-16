#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;




int score(int num){

	int den = (2*num)-1;
	int n=0 ;
	int no = num*num;
	int arr[no+1];
	memset(arr,0,sizeof(arr));
	int hash[num*num+1];
	memset(hash,0,sizeof(hash));
	int c=-1;
	int j=2;
	int k=2;
	hash[1]=1;
	for(int i=1 ; i<=num*num ; i+=k ){
//		cout<<"Diagonal: "<<i<<endl;
		 hash[i] = 1;
		 c++;
		 if(c==4){
		 	c=0,k=k+2;
		 }
	}
	if(no > 2){
		for(int i=2 ; i<=no ; i++){
		if(arr[i]==0){
			
			if(hash[i]){
//				cout<<"Prime: "<<i<<endl;
				n++;
			}
			int a=2;
			for(int j=i*a ; j <= no ; ){
				if(arr[j]==0){
					arr[j]=1;	
				}
				a++;
				j= i*a;
			}
		}
		}
	    
	}
	return n;
		
	
}
int main(){
	int n;
	scanf("%d",&n);
	int num = 3;
	while(1){
		int val = score(num);
		int d = (2*num)-1;
//		cout<<"d :"<<d<<endl;
		float f = (float)val/(float)d;
//		printf("%f\n",f);
		float ans = ((float)val/(float)d)*100;
		int v = round(ans);
		if(v < n)
			break;
		num+=2;
	//	break;
	}
	printf("%d",num);

}


