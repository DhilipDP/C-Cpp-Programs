#include<iostream>
using namespace std;

int main()
{
		int mat[][3]={1,2,3,4,5,6,7,8,9};
		int sum=0;
		for(int i=1 ; i<=2 ; i++){
			for(int j=0 ; j<=2 ; j++)
				sum+=mat[i][j];
		}
		cout<<"Sum: "<<sum;
		return 0;
}

