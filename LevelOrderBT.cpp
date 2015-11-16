//  Definition for binary tree
  
  #include<iostream>
  #include<vector>
  #include<queue>
  
  using namespace std;
  
  
  struct TreeNode {
 
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 
 
	bool  isBST(TreeNode * root,int mini,int maxi){
		if(!root)
			return true;
		if(root -> val < mini || root->val > maxi)
			return false;
		return isBST(root->left,mini,root->data-1) && isBST(root->right,root->data +1 ,maxi);
	
	}
	
  	bool isValidBST(TreeNode *root) {
        int min = INT_MIN,max = INT_MAX;
        return isBST(root,mini,maxi);
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > v;
    	vector<int> temp ;
    	if(root==NULL)
    		return v;
    	queue<TreeNode *> q;
		q.push(root);
		q.push(NULL);
		int c=0;
		while(!q.empty() && c!=2){
		// cout<<"hi";
			TreeNode * t = q.front();
			q.pop();
			
			if(t==NULL){
				c++;
				if(temp.size() !=0)
				{	v.push_back(temp);
			//	cout<<"ji";
				}
				temp.clear();
				q.push(NULL);
			}
			else{
				c=0;
			//	cout<<t->val<<" ";
			//	break;
				temp.push_back(t->val);
				if(t->left)
					q.push(t->left);
				if(t->right)
					q.push(t->right);
			}
		}
		return v;
    }
    
    
    void * getMirror(TreeNode * t){
    	if(t){
	    	getMirror(t->left);
	   		getMirror(t->right);
	    	TreeNode * temp = t->left;
	    	t->left =  t->right;
	    	t->right =  temp;
	    	}
    	}
	
    bool isSymmetric(TreeNode *root) {
    	if(root==NULL)
    		return true;
    	if(root->left == NULL && root->right==NULL)
    		return true;
    	if(root->left == NULL || root->right==NULL)
    		return false;
    	return (isSymmetric(root->left) && isSymmetric(root->right));
	}
    
    


int main(){

 TreeNode * root = new TreeNode (1);
root->left = new TreeNode(1);
/* root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
 root->left->left = new TreeNode(3); */
 if(isValidBST(root))
 	cout<<"Symmetric"<<endl;
else
	cout<<"Not Symmetric"<<endl;
 vector <vector <int> > v = levelOrder(root); 

 vector<vector <int> > :: iterator vt;
 vector<int> :: iterator it;
 int i;
 //cout<<endl<<v.size();
 for(vt=v.begin() ,i=0;  vt!=v.end() ; vt++,i++){
 	for(it= v[i].begin() ; it!= v[i].end() ; it++)
 		cout<<*it<<" ";
 	cout<<endl;
 }
 //cout<<endl<<v.size();

}
