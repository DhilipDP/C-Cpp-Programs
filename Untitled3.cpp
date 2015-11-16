#include<iostream>
#include<stdio.h>
using namespace std;
struct tree 
{
	int val;
	struct tree *left;
	struct tree *right;
	struct tree *next;
	struct tree *back;
};
struct tree *insert(struct tree *&root,int val)
{
	if(root==NULL)
	{
		struct tree *nn=new tree;
		nn->val=val;
		nn->left=NULL;
		nn->right=NULL;
		root=nn;
	}
	else if(val<root->val)
	   root->left=insert(root->left,val);
	   else
	   root->right=insert(root->right,val);
	   return root;
}
void inorder(struct tree *root)
{
	if(root==NULL) return;
     inorder(root->left);
     printf("%d",root->val);
      inorder(root->right);
}
struct tree  * delsum(struct tree *root,int key,int sum,int *flag)

{  
	 if(root==NULL) return root;
	 int lf=0,rf=0;
	 sum+=root->val;
	 root->left=delsum(root->left,key,sum,&lf);
	 root->right=delsum(root->right,key,sum,&rf);
	 if((root->right==NULL && root->left==NULL))
	 {
	 	if(sum>=key)
	 	{    *flag=1;
	 	//	struct tree *temp=root;
	 		root=NULL;
	 	//	delete(temp);
	 		return root;
		 }
		 else if(lf==1 && rf==1)
	 {
	 	//struct tree *temp=root;
	 		root=NULL;
	 	//	delete(temp);
	 	return root;
	 }
		 
	 }
	 
	return root;
}
int main()
{
	struct tree *root=NULL;
    struct tree *sub=NULL;

	root=insert(root,5);
	root=insert(root,3);
	root=insert(root,6);
		//root=insert(root,20);
	

    inorder(root);
    int fl=0;
     struct tree *res=delsum(root,2,0,&fl); 
	printf("\n");
	inorder(res);
    return 0;
}
