#include<iostream>
#include<queue>
#include<vector>
using namespace std ;


struct comp1{

bool operator()(int &a , int &b)
{
	return a < b;
}
};


struct comp2{

bool operator()(int &a , int &b)
{
	return a > b;
}
};

priority_queue<int,vector<int> ,comp1> max_heap ;
priority_queue<int,vector<int> ,comp2> min_heap ;


void findMedian(int x,int &m)
{
	//cout<<"hi"<<endl;
	int diff   = max_heap.size() - min_heap.size() ;
	//cout<<diff<<endl ;
	switch(diff){
		case 0 : 
				//cout<<"eaual"<<endl;
				if( x < m){
					max_heap.push(x) ;
					m = max_heap.top() ;
				//	cout<<"pushing in max "<<x<<endl;
				}
				else{
				//	cout<<"pushing in min "<<x<<endl;
					min_heap.push(x);
					m = min_heap.top() ;
					
				}
				break;
		case 1: 
				//cout<<"left"<<endl;
				if( x < m){
				//		cout<<"pushing in min "<<max_heap.top()<<endl;
					min_heap.push(max_heap.top());
					max_heap.pop();
					max_heap.push(x);
				//	cout<<"pushing in max "<<x<<endl;
				}
				else{
				//		cout<<"pushing in min "<<x<<endl;
					min_heap.push(x);
				}
				m = (min_heap.top() + max_heap.top())/2 ;
				break;
		case -1 :
				//	cout<<"greater"<<endl;
				 if( x < m)
					max_heap.push(x) ;//cout<<"pushing in max "<<x<<endl;
				 else{
				 //		cout<<"pushing in max "<<min_heap.top()<<endl;
				 	max_heap.push(min_heap.top()) ;
				 	min_heap.pop();
				 //		cout<<"pushing in min "<<x<<endl;
				 	min_heap.push(x);
				 }
				 m = (min_heap.top() + max_heap.top())/2 ;
	}
}
int main()
{
	int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int size = sizeof(A)/sizeof(A[0]);
    int median = 0;
    for(int i=0 ; i<size ; i++)
    {
    	cout<<"Elements : "<<endl;
    	for(int j=0 ; j<=i ; j++)
    		cout<<A[j]<<" " ;
    	
		findMedian(A[i],median);
		
		cout<<endl<<"Median : "<<median<<endl;
    }
}
