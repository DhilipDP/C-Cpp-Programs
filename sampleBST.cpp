#include<stdio.h>
#include<malloc.h>
#include<iostream>

using namespace std;
struct node{
	int info;
	struct node *lchild;
	struct node *rchild;
}*root;

void find(int item,struct node **par,struct node ** loc){
	struct node *ptr,*ptrsave;
	if(root==NULL){
		*loc=NULL;
		*par=NULL;
		return;
	}
	if(item==root->info){
		*loc=root;
		*par=NULL;
		return;
	}

	if(item<root->info){
		ptr=root->lchild;
	}
	else{
		ptr=root->rchild;
	}
	ptrsave=root;
	*par = root;
	while(ptr!=NULL){
	//	cout<<"searching "<<ptr->info<<endl;
		if(item==ptr->info){
			*loc=ptr;		
			*par=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr->info){
			ptr=ptr->lchild;
		}
		else{
			ptr=ptr->rchild;
		}
		*loc=NULL;
		*par=ptrsave;
	}
	
}
void insert(int item){
	struct node *temp=NULL,*parent=NULL,*location=NULL;
	find(item,&parent,&location);
	if(location!=NULL){
		printf("item already present");
		return;
	}
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=item;
	temp->lchild=NULL;
	temp->rchild=NULL;
	if(parent==NULL){
		root=temp;
	}
	else{
		if(item<parent->info)
							 parent->lchild=temp;
	    else
	    					 parent->rchild=temp;
	}
}
void inorder(struct node *ptr){
	if(root==NULL){
		printf("the tree is empty");
		return;
	}
	if(ptr!=NULL){
		inorder(ptr->lchild);
		printf("%d",ptr->info);
		inorder(ptr->rchild);
	}
}

main(){
	int num;
	printf("enter the num to be inserted");
	scanf("%d",&num);
	insert(num);
	printf("enter the num to be inserted");
	scanf("%d",&num);
	insert(num);
	printf("enter the num to be inserted");
	scanf("%d",&num);
	insert(num);
	inorder(root);
}

