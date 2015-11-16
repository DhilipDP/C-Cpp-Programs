#include<iostream>

using namespace std ;

struct Interval
{
	int low,high ;
};

struct node{
	Interval I ;
	int max ;
	struct node * left;
	struct node * right ;
	node(Interval i) : I(i) , max(i.high) , left(NULL) , right(NULL) {}
};


struct node * insert(struct node * root,Interval i)
{
	if(root==NULL)
	{
		root = new node(i) ;
		return root;
	}
	if(root->I.low < i.low )
		root -> right = insert(root->right,i) ;
	else
		root -> left = insert(root->left,i) ;
	if(root->max < i.high)
		root->max = i.high ;
	return root ;
}

bool isOverlap(Interval a,Interval b)
{
	if(b.low < a.high && b.high > a.low)
		return true ;
	return false;
}
Interval overlap(struct node * root,Interval i)
{
	
	Interval it = {-1,-1};
	if(root==NULL)
		return it;
	//cout<<root->I.low<<endl;
	if(isOverlap(root->I,i))
		return root->I;
	if((root->left) && i.low < root->left->max)
		return overlap(root->left,i);
	return overlap(root->right,i);
}

void printConflicting(Interval Int[] , int n)
{
	if(n==0)
		return ;
	struct node * root = NULL ;
	root = insert(root,Int[0]) ;
		for(int i=1 ; i<n ; i++)
	{
		Interval ovlap = overlap(root,Int[i]) ;
		if(ovlap.low!=-1)
			cout<<"["<<ovlap.low<<","<<ovlap.high<<"] & ["<<Int[i].low<<","<<Int[i].high<<"]"<<endl;
		root = insert(root,Int[i] );
	}
}

int main()
{
	Interval appt[] = { {1, 5}, {3, 7}, {2, 6}, {10, 15},
                        {5, 6}, {4, 100}};
    int n = sizeof(appt)/sizeof(appt[0]);
    cout << "Following are conflicting intervals\n";
    printConflicting(appt, n);
    return 0;
}
