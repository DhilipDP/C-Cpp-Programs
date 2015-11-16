/* A Naive recursive implementation of 0-1 Knapsack problem */
#include<stdio.h>
 #include<iostream>
 
 using namespace std ;
 
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n,int C)
{
	
	cout<<W<<" "<<n<<" "<<C<<endl;
   // Base Case
   if (n == 0 || W == 0 ||  C==0){
		cout<<"returnninf" <<endl;
       return 0;
}
    
 
   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   if (wt[n-1] > W){
  	cout<<"eliminating"<<endl; 
       return knapSack(W, wt, val, n-1,C);
 }
   // Return the maximum of two cases: (1) nth item included (2) not included
   else {
 	cout<<"here of "<< n <<" "<<W<<endl;
 	int A = val[n-1] + knapSack(W-wt[n-1], wt, val, n-1,C-1);
 	int B =     knapSack(W, wt, val, n-1,C);
 	
                
   int v = max( A,B  );
 	cout<<"here of "<< n <<" "<<W<<" RETURN S" <<  A << " "<<B<< endl;
 	return v;
                  
                  
}}
 
// Driver program to test above function
int main()
{
    int val[] = {10, 20, 30};
    int wt[] = {20, 30, 40};
    int  W = 60;
    int n = sizeof(val)/sizeof(val[0]);
 	int c = 2;
    printf("%d", knapSack(W, wt, val, n ,c ));
    return 0;
}
