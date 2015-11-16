#include<algorithm>
#include<vector>
#include<iostream>
using namespace std ;

struct node{
	int val ;
	struct node * left ;
	struct node * right ;
	node(int x) : val(x) , left(NULL) , right(NULL) {}
};



int diameter(struct node * root,int &height,vector<int> &diam , vector<int> &longest)
{
	if(!root){
		height = 0;
		return 0;
	}

	int lh = 0,rh=0;
	vector<int> l_diam , r_diam  , l_longest , r_longest;

	int l = diameter(root->left,lh,l_diam,l_longest) ;
	int r = diameter(root->right,rh,r_diam,r_longest ) ;

	height = max(lh,rh) + 1 ;

	if(height==1)
	{
		diam.push_back(root->val);
		longest.push_back(root->val);
		return 1;
	}

	int maxi_diameter =  max(max(l,r) , lh+rh+1);

	if(maxi_diameter==l)
	{
		diam = l_diam ;
	}
	else if(maxi_diameter==r)
	{
		diam = r_diam ;
	}
	else{
		diam = l_longest ;
		diam.push_back(root->val ) ;
		diam.insert(diam.end() , r_longest.begin() , r_longest.end());
	
		if(lh >= rh){
			longest = l_longest ;
			longest.push_back(root->val);
		}
		else{
			longest.push_back(root->val);
			longest.insert(longest.end() , r_longest.begin() , r_longest.end()) ;
		}
		
	}
	return maxi_diameter;
}

int main()
{
	struct node * root = NULL ;
	/*
			 	 
                      20
                    /    \
                    
                  8       22
                /   \    /   \
              5      3 4     25
                    / \      
                  10   14 
                  		\
                  		 24
                  		  \
                  		  34
      
    */
   
    root = new node(20);
	root -> left = new node(8) ;
    root -> right = new node(22);
   root -> right -> left = new node(4);
  	root -> left -> left = new node(5) ;
 	root -> left -> right = new node(3) ;
   root -> right -> right = new node(25) ;
    root -> left->right->left = new node(10); 
    root -> left -> right -> right = new node(14); 
	 root -> left -> right -> right -> right = new node(24); 
	 root -> left -> right -> right -> right ->right = new node(34); 
	int height = 0;
	vector<int> diameter_nodes;
	vector<int> longest_nodes ;
  cout<< "Diameter : " << diameter(root,height,diameter_nodes,longest_nodes) <<endl;	
   //cout<<height<<endl;
   for(int i=0 ; i<diameter_nodes.size() ; i++)
   	cout<<diameter_nodes[i]<<" ";
}
