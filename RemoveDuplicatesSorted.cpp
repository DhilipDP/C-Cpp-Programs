#include<iostream>
#include<vector>

using namespace std ;

int removeElement(vector<int> &A, int B) {
    
    int n = A.size() ;
   int index1 = 0;
   int index2 = 0 ;
   for(int i=0 ; i<n ; i++){
       if(A[i]!=B)
       	A[index2++] = A[index1++];
       else
           index1++;
   }
   cout<<index2<<endl;
   A.erase(A.begin() + index2,A.end());
   return A.size() ;
}



int main()
{
	vector<int>  v ;
	v.push_back(1);
		v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	v.push_back(3);
	removeElement(v,1) ;
	vector<int > :: iterator it ;
	for(it = v.begin() ;  it!=v.end() ; it++)
		cout<<*it<<" ";
}
