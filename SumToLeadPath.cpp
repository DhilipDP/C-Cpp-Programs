 #include<iostream>
#include<stdlib.h>
 using namespace std ;
 
 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 
 
 void solve(TreeNode * A,string s,int &sum)
 {
     if(A==NULL){
       
        return ;
     }
     s += ((A->val) + '0' );
   if(A->left == NULL && A->right==NULL){
         int v = atoi(s.c_str());
        
        sum = (sum + v)%1003 ;
   }
    solve(A->left,s,sum);
    solve(A->right,s,sum);
 }
int sumNumbers(TreeNode* A) {
    string s="";
    int sum = 0;
    solve(A,s,sum);
    return sum%1003 ;
}


int main()
{
	TreeNode * A = new TreeNode(1) ;
	A -> left = new TreeNode(2) ;
	A -> right = new TreeNode(3) ;
	A -> left -> left = new TreeNode(4) ;
	cout<<sumNumbers(A);
}
