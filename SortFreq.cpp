#include<iostream>
using namespace std;

int size = 1;
struct node{
	int data;
	int count;
	int firstindex;
	node * left;
	node * right;
};


struct arr_node{
	int val;
	int cnt;
	int ind;
};
struct node * insert(struct node * t, int val,int index)
{
	if(t==NULL){
		t=new node();		
		t->data = val;
		t->count = 1;
		t->firstindex = index;
		t->left=NULL;
		t->right=NULL;
	}	
	else if(val < t->data)
		t->left = insert(t->left,val,index);
	else if(val > t->data)
		t->right = insert(t->right,val,index);
	else
		(t->count) ++;
	return t;
		
}

void inorder(node * root,arr_node a[])
{
	if(root!=NULL){
		inorder(root->left,a);
		a[size].val=root->data;
		a[size].cnt=root->count;
		a[size].ind=root->firstindex;
		size++;
		inorder(root->right,a);
	}
}

void heapify(arr_node a[],int n,int i)
{
	int largest=i;
	if(2*i <= n ){
		if(a[2*i].cnt > a[i].cnt )
			largest = 2*i;
		else if(a[2*i].cnt == a[i].cnt){
			largest = a[2*i].ind < a[i].ind ? 2*i : i;
		}
		else
		   largest = i;
	}
	if((2*i) + 1 <= n){
		if(a[2*i+1].cnt > a[largest].cnt )
			largest = 2*i+1;
		else if(a[2*i+1].cnt == a[largest].cnt){
			largest = a[2*i+1].ind < a[largest].ind ? 2*i+1 : largest;
		}
	}
	if(largest!=i){
		arr_node temp = a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,n,largest);
	}
}

void buildHeap(arr_node a[],int n){
	for(int i=n/2 ; i>=1 ; i--)
		heapify(a,n,i);
		
}

void extract(arr_node a[],int n)
{
	while(n>=2){
		arr_node temp = a[1];
		a[1]=a[n];
		a[n]=temp;
		n--;
		heapify(a,n,1);
	}
}

int main()
{
	int i,n;
	cout<<"\nNumber of ELements: ";
	cin>>n;
	cout<<"Elements: ";
	struct node *root = NULL;
	struct arr_node my_arr[n];;
	for(i=0 ; i<n ; i++){
		int val;
		cin>>val;
		root=insert(root,val,i);
	}
	inorder(root,my_arr);
	buildHeap(my_arr,size-1);	
	extract(my_arr,size-1);
	cout<<"Solution: ";
	for(i=size-1 ; i>0 ; ){
		if(my_arr[i].cnt!=0){
			cout<<my_arr[i].val<<" ";
			my_arr[i].cnt--;
		}
		else{
			i--;
		}
	}	
}
