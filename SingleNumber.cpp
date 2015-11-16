#include<iostream>

using namespace std ;

int main(){
	
	int A[] ={1,1,1,2,2,2,3};
	int n = sizeof(A)/sizeof(A[0]);
	int num = 0;
    for(int i=0 ; i<n ; i++)
            num = num ^ A[i];
        cout<<num<<endl;
}
