#include <iostream>
#include <climits>
using namespace std;
 
/* A binary tree Node has key, pocharer to left and right children */
struct Node
{
	char key;
	struct Node* left, *right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pocharers. */
Node *newNode(char k)
{
	Node *node = new Node;
	node->key = k;
	node->right = node->left = NULL;
	return node;
}
 
// A utility function to find minimum of x and y
int getMin(int x, int y)
{
	return (x < y)? x :y;
}
 
//This function performs post order traversal
int post_order_traversal(struct Node *current,char key,bool &key_visited,int &total_min)
{
	if(current==NULL)
		return 10000;

	cout<<"In : "<<current->key<<endl; 
	if(current->left==NULL&&current->right==NULL)//To check if it's leaf
	{
		cout<<"leaf"<<endl;
		if(current->key==key)
			total_min=0;//incase the key is the leaf itself.
		return 1;
	}
	int left_min,right_min,current_min;
 
	bool left_visit=false;//To check where the key lies ie left or right while going back after visiting the key.
 
	left_min=post_order_traversal(current->left,key,key_visited,total_min);
 
	if(key_visited)//It will be true if the key lies on the left side since we not yet traversed right path.
		left_visit=true;
 
	right_min=post_order_traversal(current->right,key,key_visited,total_min);
 
	current_min=getMin(left_min,right_min);
 
	if(current->key==key)
	{
		total_min=getMin(total_min,current_min);
		cout<<"updating total min to"<<total_min<<endl;
		key_visited=true;
		return 1;
	}
	if(key_visited)//Its used to find the distance from the top.
	{
		
		total_min=getMin(total_min,left_min+right_min); //left_min+right_min because we need to travel from key to current node and from current node to leaf.
		cout<<"Updating total min to"<<total_min<<endl;
		if(left_visit){
				cout<<"Left returning :"<<left_min+1<<endl;
			return left_min+1;
			}//if the key lies in the left side
		else
		{
				cout<<"Right returning :"<<right_min+1<<endl;
			return right_min+1;
			}//if the key lies in the right side
	}
	cout<<"returning :"<<current_min+1<<endl;
	return current_min+1;//1 is the distance from the current node to its parent. so its added to the minimum
}
int findClosest(struct Node *root,char key)
{
	int total_min=100000;//It contains the value of minimum closest leaf. Initially assigning some large value
	bool key_visited=false;//Used to check whether the key is visited
	post_order_traversal(root,key,key_visited,total_min);
	return total_min;
}
/* Driver program to test above functions*/
int main()
{
	// Let us construct the BST shown in the above figure
	struct Node *root        = newNode('A');
	root->left               = newNode('B');
	root->right              = newNode('C');
	root->right->left        = newNode('E');
	root->right->right       = newNode('F');
	root->right->left->left  = newNode('G');
	root->right->left->left->left  = newNode('I');
	root->right->left->left->right = newNode('J');
	root->right->right->right      = newNode('H');
	root->right->right->right->left = newNode('K');
 
	char k = 'C';
	cout << "Distace of the closest key from " << k << " is "
		<< findClosest(root, k) << endl;
/*	k = 'H';
	cout << "Distace of the closest key from " << k << " is "
		<< findClosest(root, k) << endl;
	k = 'E';
	cout << "Distace of the closest key from " << k << " is "
		<< findClosest(root, k) << endl;
	k = 'B';
	cout << "Distace of the closest key from " << k << " is "
		<< findClosest(root, k) << endl;
 */
	return 0;
}
