 
 #include<iostream>
 using namespace std ;
 
  bool canJump(int A[], int n) {
        if(n<=0)
            return false;
        for(int i=0 ; i<n ; i++){
        	if(A[i]==n-i-1)
        		return true;
		}
		return false;
        
    }
    
    int main(){
    	int a[] = {3,2,1,0,4};
    	cout<<canJump(a,5);
	}
