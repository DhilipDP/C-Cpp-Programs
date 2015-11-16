#include<iostream>
#define comb 3

using namespace std ;


void print(int n,int index,int arr[]){
	cout<<n<<" "<<index<<endl;
	if(n==0)
	{
		for(int  i = 0 ; i<index ; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	else if(n > 0){
		
		for(int k=1 ; k<=comb ; k++){
			cout<<"arr["<<index<<"]"<<" : "<<k<<endl;
			arr[index] = k;
			print(n-k,index+1,arr);
		}
	
	}
		
}


int main(){
	
	int n= 4;
	int arr[100];
	print(n,0,arr);
}
