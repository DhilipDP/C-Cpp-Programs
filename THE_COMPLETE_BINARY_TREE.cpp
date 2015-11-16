#include<iostream>
#include<queue>
#include<math.h>
#include<stack>
#include<limits.h>
#include<stdlib.h>
#include<algorithm>
using namespace std ;


struct node{
	int data ;
	node * left ;
	node * right ;
};



void insert(struct node *&root , int val,queue<node *> &q){
	cout<<"Inserting: ";
		
		struct  node * newnode = new node ;
		newnode->data = val;
		newnode->left = newnode->right = NULL;
		if(root==NULL){
			root = newnode;

			cout<<val<<" atRoot"<<endl;
		}
		else{
			cout<<val<<" ";
			struct node * front = q.front();
			
			if(!(front->left)){
				cout<<"at left of "<<front->data<<endl;
				front->left = newnode ;
			}
			else if(!(front->right)){
				cout<<"at right of "<<front->data<<endl;
				front->right =  newnode;
			}
			else{
				q.pop();
				struct node * ft = q.front();
				cout<<"at left of "<<ft->data<<endl;
				ft->left = newnode ;
			}
		}
		q.push(newnode);
}

int height(struct node * t){

	if(t==NULL)
		return -1 ;
	int lh = height(t->left);
	int rh = height(t->right);
	
	return lh > rh ? lh +1 : rh + 1 ;	

}


void printGivenLevel(struct node * t,int level){
	if(t==NULL)
		return ;
	if(level==0){
		cout<<t->data<<" ";
	}
	else{
		printGivenLevel(t->left,level-1);
		printGivenLevel(t->right,level-1);
	}
}

void levelOrder(struct node * root){
	if(root == NULL){
		cout<<"The Tree is EMPTY"<<endl;
		return ;
	}
	int h = height(root);
	cout<<"The height is :"<<h<<endl;
	int i;
	for(i=0 ; i<=h ; i++)
		printGivenLevel(root,i),cout<<endl;
}



void printGivenLevelZigZag(struct node * t,int level,int val){
	if(t==NULL)
		return ;
	if(level==0){
		cout<<t->data<<" ";
	}
	else{
		if(val){
		printGivenLevelZigZag(t->right,level-1,val);
		printGivenLevelZigZag(t->left,level-1,val);
		}
		else{
			printGivenLevelZigZag(t->left,level-1,val);
			printGivenLevelZigZag(t->right,level-1,val);
		}
	}
}
void zigZagOrder(struct node * root){
	if(root == NULL){
		cout<<"The Tree is EMPTY"<<endl;
		return ;
	}
	int h = height(root);
	cout<<"The height is :"<<h<<endl;
	int i;
	for(i=0 ; i<=h ; i++)		
		printGivenLevelZigZag(root,i,i%2),cout<<endl;
}


void level(struct node * t){

	int level = 0;
	int count = 0;
	if(t==NULL){
		cout<<"The Tree is EMPTY"<<endl;
		return ;
	}
	struct node *  temp ;
	queue<node *> q ;
	q.push(t);
	while(!q.empty()){
		temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		count++;
		if(count == pow(2,level))
			cout<<endl,level++,count=0;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);		
	}		
}


void spiralOrder(struct node * t){
		stack<node *> sRight ;
		stack<node *> sLeft ;
		
		sLeft.push(t);
		int count=0,level=0;
		while(!sLeft.empty() || !sRight.empty()){
			while(!sLeft.empty()){
				struct node * temp = sLeft.top();
				cout<<temp->data<<" ";
				count++;
				if(count == pow(2,level))
					level++,count=0,cout<<endl;
				sLeft.pop();
				if(temp->left)
					sRight.push(temp->left);
				if(temp->right)
					sRight.push(temp->right);
			}
			while(!sRight.empty()){
				struct node * temp = sRight.top();
				cout<<temp->data<<" ";
				count++;
				if(count == pow(2,level))
					level++,count=0,cout<<endl;
				sRight.pop();
				if(temp->right)
					sLeft.push(temp->right);
				if(temp->left)
					sLeft.push(temp->left);
			}
		}
}


void mirrorTree(struct node * t){
	
	if(t==NULL)
		return ;
		
	mirrorTree(t->left);
	mirrorTree(t->right);
	struct node * temp = new node ;
	temp = t->left ;
	t->left = t->right ;
	t->right = temp ;	
}

int search(struct node * t,int val){
	if(t==NULL)
		return 0;
	if(t->data==val || search(t->left,val) || search(t->right,val))
			return 1 ;
	return 0;
}


struct node * findLca(struct node * t,int n1,int n2){
	
	if(t==NULL)
		return NULL;
	if(t->data==n1 || t->data==n2)
		return t;
	struct node * llca = findLca(t->left,n1,n2);
	struct node * rlca = findLca(t->right,n1,n2);
	
	if(llca && rlca)
		return t;
	return llca!=NULL ? llca : rlca ;	
}

void lca(struct node * t,int n1,int n2){
	int f=0;
	if(t==NULL){
		cout<<"\nRoot is EMpty"<<endl ;
		return;	
	}
	if(!search(t,n1)){
		
		cout<<"Check the values Please!"<<endl;
		return ;
	}
//	cout<<n2<<" "<<search(t,n2,f);
	if( !search(t,n2))
	{
		cout<<"Check the values Please!"<<endl;
		return ;
	}
	struct node * lca = new node;
	
	lca = findLca(t,n1,n2);
	
	cout<<lca->data<<" ";

}


void reverseLevelOrder(struct node * t){

	int arr[100000];
	memset(arr,0,sizeof(arr));
	queue<node *> q ;
	stack<int> s ;
	q.push(t);
	int count = 0;
	int sum = 0;
	while(!q.empty()){
		struct node * front = q.front();
		s.push(front->data);
		count++;
		int ch = count + 1 ;
		if(!(ch & (ch-1))){
			arr[front->data]=1;
		}
		q.pop();
		
		if(front->right)
			q.push(front->right);
		if(front->left)
			q.push(front->left);
	}	
	
	while(!s.empty()){
		int val=s.top();
		if(arr[val])
			cout<<endl;
		cout<<val<<" ";
		
		s.pop();
	}
}

int isBST(struct node * t,int min,int max){
	if(t==NULL)
		return 1 ;
	if(t->data < min || t->data > max)
		return 0;
	return (isBST(t->left,min,t->data -1) && isBST(t->right,t->data+1 ,max));

	
	//return 0 ;
}

int isBST(struct node * t ){
	return isBST(t,INT_MIN,INT_MAX);
}


bool isBalanced(struct node * t){
	if(t==NULL)
		return true ;
	int lh = height(t->left) ;
	int rh = height(t->right) ;
	
	if(abs(lh-rh) <= 1 && isBalanced(t->left) && isBalanced(t->right))
		return true ;
	return false ; 
}

int maxi(int a,int b){
	return a>b ? a : b ;
}

int maxi(int a,int b,int c){
	return maxi(maxi(a,b),c);
}
int diameter(struct node * t){
	if(t==NULL)
		return 0 ;
	int ldiam = diameter(t->left);
	int rdiam = diameter(t->right);
	int lh = height(t->left)+1 ;
	int rh = height(t->right) + 1;
	return maxi(ldiam,rdiam,lh+rh+1);
}

int maxSum(struct node * t,int &s){
	if(t==NULL)
		return 0;
		
	int lSum = maxSum(t->left,s);
	int rSum = maxSum (t->right,s);
	
	int cur_sum = maxi((lSum + rSum + t->data ), maxi(lSum  , rSum)) ;
	if(cur_sum  > s)
		s = cur_sum ;
	return maxi(lSum,rSum) + t->data ;
	
}


int count_nodes(struct node * t,int &i){
	if(t!=NULL){
		count_nodes(t->left,i);
		i++;
		count_nodes(t->right,i);
	}
}

void store_inorder(struct node * t,int *&arr,int &index){
	if(t!=NULL){
		store_inorder(t->left,arr,index);
		arr[index++]=t->data ;
		store_inorder(t->right,arr,index);
	}
}


bool comp(int a,int b){
	return a < b ;	
}


void arr_to_BST(struct node * root , int *&arr,int &index){
	if(root!=NULL){
		arr_to_BST(root->left,arr,index);
		root -> data = arr[index++];
		arr_to_BST(root->right,arr,index);
	}	
}


int isSiblings(struct node * root,struct node * a,struct node * b){
	if(root == NULL)
		return 0;
	return ((root->left == a && root->right==b) || (root->left==b && root->right==a) || isSiblings(root->left,a,b) || isSiblings(root->right,a,b));
}
int level(struct node * root,struct node * n,int lev){
	if(root==NULL)
		return 0;
	if(root==n)
		return lev ;
	int l = level(root->left,n,lev+1);
	if(l!=0)
		return l;
	return level(root->right,n,lev+1);
}
int isCousin(struct node * root,struct node * a,struct node * b) {
	if(root==NULL)	
		return 0;
	if((level(root,a,1)==level(root,b,1)) && !isSiblings(root,a,b))
		return 1 ;
	return 0;
}

int main(){

	struct node * root = NULL ;
	queue<node *> q ;
	
	cout<<"Insertion:\n"<<endl ;
	
	insert(root,7,q);
	insert(root,4,q);
	insert(root,9,q);
	insert(root,11,q);
	insert(root,14,q);
	insert(root,1,q);
	insert(root,5,q);
	insert(root,10,q);
	insert(root,2,q);
	
	cout<<"\n\nLevel Order traversal:"<<endl ;
		
	levelOrder(root);	
	
	cout<<"\n\nUsing Queue: "<<endl ;
	
	level(root);
	
	cout<<"\n\nZigZag level Order Traversal:"<<endl;
	
	zigZagOrder(root);
	
	cout<<"\n\nUsing Stacks :"<<endl;
	
	spiralOrder(root);
	
	cout<<"\n\nMirroring of a binary tree:\n"<<endl;
	mirrorTree(root);
	level(root);
	mirrorTree(root);
	
	cout<<"\n\nLCA of a Binary Tree\n"<<endl;
	cout<<"\n10 & 2"<<endl;
	lca(root,10,2);
	cout<<"\n10 & 19"<<endl;
	lca(root,10,19);
	cout<<"\n4 & 5"<<endl;
	lca(root,4,5);
	cout<<"\n7 & 2"<<endl;
	lca(root,7,2);
	
	
//	level(root);
	cout<<"\nReverse Level Order traversal: \n";
	reverseLevelOrder(root);
	
	cout<<"\n\nChecking whether this tree is a BST!\n";
	levelOrder(root);
	if(isBST(root))
		cout<<"\nYes!! A BST\n!:)";
	else{
		cout<<"Ooops!! nope \n";
				cout<<"\nConverting into BST\n";
		int n = 0;
		count_nodes(root,n);
		int *arr = new int[n];
//		cout<<n<<endl;
		int index = 0;
		store_inorder(root,arr,index);
		sort(arr,arr+index,comp);
		index = 0;
		arr_to_BST(root,arr,index);
		cout<<"\nConverted!\n";
		levelOrder(root);
	}
	struct node * r = NULL ;
	cout<<"\nCreating new Binary tree : \n";
	queue<node * > q1 ;
	insert(r,7,q1);
	insert(r,3,q1);
	insert(r,9,q1);
	insert(r,1,q1);
	insert(r,4,q1);
	insert(r,8,q1);
	insert(r,11,q1);
	
	levelOrder(r);
	
	cout<<"\n\nChecking whether this tree is a BST!\n";
	
	if(isCousin(r,r->left->left,r->left->right))
		cout<<"Cousins:\n";
	else
		cout<<"Not Cousins\n";
	if(isBST(r))
		cout<<"\nYes!! A BST!:)";
	else{
		cout<<"Ooops!! nope \n";
	//insert(r,)

	}
	
	cout<<"\nIs this BST balanced ?\n" ;
	
	if(isBalanced(r))
		cout<<"\nYeah.. A balanaced BST\n";
	else
		cout<<"\nNo it is not!!\n";	
		
	struct node * tree = NULL ;
	queue<node *> q2 ;
	for(int i=1 ; i<=5 ; i++)
		insert(tree,i,q2);
	levelOrder(tree);
	
cout<<endl<<"The diameter is:"<<	diameter(tree);

	cout<<"\nMaximum sum between two leafs\n";
	int sum = 0;
	
	maxSum(tree,sum);
	
	cout<<endl<<sum<<endl;
}
