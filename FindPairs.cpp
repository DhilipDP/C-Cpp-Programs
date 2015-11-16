#include<iostream>
#include<stdio.h>
#include<limits.h>

#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
using namespace std ;

/* Question :
FInd the number of pairs with sum 'k'
Input :
1 2 3 4
4
Output:
1
 */

int main(){
	int m = 0;
	int n=-m;
	cout<<n;
	int *numbers ;
	int target ;
	int no_of_elements,iterator ;
	cout<<"No of elements : "<<endl;
	s(no_of_elements); 
	numbers  = new int[no_of_elements];
	cout<<"Enter elements: "<<endl ;
	int min = 0,max = INT_MIN ;
	for(iterator = 0; iterator < no_of_elements ; iterator++)
	{
		s(numbers[iterator]);
		if(numbers[iterator] < min)
			min = numbers[iterator] ;
		if(numbers[iterator] > max)
			max = numbers[iterator] ;
	}
	cout<<"Enter target: "<<endl;
	s(target);
	min = -min;
	int hash_array[max+min+1];
	memset(hash_array,0,sizeof(hash_array));
	for(iterator = 0 ;iterator < no_of_elements ; iterator++)
		hash_array[numbers[iterator]+min] = 1;
	int no_of_pairs = 0;
	for(iterator = 0 ; iterator < no_of_elements ; iterator++){
		int my_pair = target - numbers[iterator] ;
		if(my_pair != numbers[iterator] && my_pair + min >=0 && hash_array[my_pair + min])
		{
			cout<<"Pair!: ("<<numbers[iterator]<<","<<my_pair<<")\n";
			no_of_pairs++;
			
			hash_array[numbers[iterator]+min]=hash_array[my_pair+min]=0;
		}
	}
	cout<<"NUmber of pairs: "<<endl;
	p(no_of_pairs);
}
