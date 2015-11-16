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
	//	cout<<"Inserting: "<<val;
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
//	cout<<"hello";
	
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
	//	cout<<"hi";
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
//		cout<<"ha";
		heapify(a,n,largest);
	}
}
void buildHeap(arr_node a[],int n){
	for(int i=n/2 ; i>=1 ; i--)
		heapify(a,n,i);
		
}

void extract(arr_node a[],int n)
{
	if(n>=2){
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
	struct arr_node my_arr[n];// = new arr_node[n];
	for(i=0 ; i<n ; i++){
		int val;
		cin>>val;
		root=insert(root,val,i);
//		cout<<root->data;
	}
	inorder(root,my_arr);
	cout<<"Before heaping:\n";
	int i1,i2;
	for(i=1 ; i<size-1 ; i++)
	{
		if(my_arr[i].cnt < my_arr[i+1].cnt){
			i1 = i;
			i2 = i+1;
			
		}
	}
	arr_node temp = my_arr[i1];
			my_arr[i1] = my_arr[i2];
			my_arr[i2] = temp;
	for(i=1 ; i<size ; i++)
			cout<<i<<" "<<my_arr[i].val<<" "<<my_arr[i].cnt<<" "<<my_arr[i].ind<<endl;
	cout<<"done";
	buildHeap(my_arr,size-1);	
	int num = size;
//	extract(my_arr,size-1);
	for(i=1 ; i<num ; i++)
		cout<<endl<<my_arr[i].val<<" "<<my_arr[i].cnt<<" "<<my_arr[i].ind<<endl;
}
