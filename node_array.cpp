#include<iostream>
using namespace std;

struct node{
	int val;
	node * up,*down,*left,*right;
}*root,*t1,*t2,*t3;

void disp(){

	node * temp = new node;
	temp = root;
	for(int i=0 ; i<4 ; i++){
		cout<<temp->val<<" ";
		temp=temp->right;
	}
	cout<<endl;
	temp = t1;
	for(int i=0 ; i<4 ; i++){
		cout<<temp->val<<" ";
		temp =  temp->right;
	}
	cout<<endl;
	temp = t2;
	//cout<<t2->val;
	temp = t2;
	for(int i=0 ; i<4 ; i++){
		cout<<temp->val<<" ";
		temp =  temp->right;
	}
	
}

void accept(int arr[4][4],int r ,int c){
	node * temp = new node;
	node *t,*s;
	int i=0;
	temp->val = arr[r][c];
	temp->left = temp->up = temp->down = temp->right = NULL;
	if(r==0){
		temp->up=NULL;
		if(c==0){
			temp -> left  = NULL;
			temp->right = temp->down = NULL;
			root = temp;
		}
		else{
			t=root;
			while(t->right)
				t= t->right;
			t->right=temp;
			temp->left = t;
		}
	}
	else if(r==1){
		if(c==0){
			root->down = temp;
			temp -> left  = NULL;
			temp->right = temp->down = NULL;
			 temp->up=root;
			 t1=temp;
		}
		else{
			t = new node;
			t = t1;
			while( t->right){
				t = t->right;
			}
			temp->left = t;
			t->right = temp;
			t = root;
		
			while(i<c){
				//cout<<t->val<<" ";
				t=t->right,i++;
			}
			temp->up = t;
			t->down = temp;
		}
	}
	else if(r==2){
		if(c==0){
			t1->down = temp;
			temp -> left  = NULL;
			temp->right = temp->down = NULL;
			 temp->up=t1;
			 t2=temp;
		}
		else{
		//	t = new node;
			t = t2;
			while(t->right)
				t = t->right;
			temp->left = t;
			t->right = temp;
		
		}
	}
}
int main(){
	int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	root = t1 = t2 = NULL;
	for(int r=0 ; r<4 ; r++)
		for(int c=0 ; c<4 ; c++)
			accept(arr,r,c);
		//	return 0;
	
//	cout<<"hello";
	disp();
}
