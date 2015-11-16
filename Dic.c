#include <stdio.h>
#include <string.h>
#include<malloc.h>


	struct node{
		char word[1000];
		char meaning[1000];
		struct node *left;
		struct node *right;
	};
	
	

struct node * insert(struct node  * root,char * str,char * mea)
{
	struct node *n=(struct node*)malloc(sizeof(struct node *));
	struct node *p=(struct node*)malloc(sizeof(struct node *));
	struct node *q=(struct node*)malloc(sizeof(struct node *));
	printf("hey");
	strcpy(n->word,str);
	printf("come on");
	strcpy(n->meaning,mea);
	n->left=n->right=NULL;
	if(root==NULL){
		root=n;
		printf("Inserted %s into the dictionary\n",str);
	}
	else{
		p=q=root;
		while(p!=NULL){
			q=p;
			if(strcmp(str , p->word) < 0)
				p=p->left;
			else if(strcmp(str , p->word) > 0)
				p=p->right;
			else 
				break;
		}
		if(strcmp(str , q->word) < 0){
			printf("Inserted %s into the dictionary\n",str);
			q->left=n;
		}
		else if(strcmp(str , p->word) > 0){
			printf("Inserted %s into the dictionary\n",str);
			q->right=n;
		}
		else ; 
	}
	return root ;
}
int  search_element(struct node *t,char * str)
{
	if(t==NULL)
		return 0;
	else if(strcmp(str , t->word) < 0)
		return search_element(t->left,str);
	else if(strcmp(str , t->word) > 0)
		return search_element(t->right,str);
	return 1;
}
int search(struct node *root,char * str)
{
	if(search_element(root,str))
		return 1;
	else
		return 0;
}
void  find_meaning(struct node *t,char * str)
{
	 if(strcmp(str , t->word) < 0)
		find_meaning(t->left,str);
	else if(strcmp(str , t->word) > 0)
		find_meaning(t->right,str);
	else {
		printf("\nWord Found!!\n ");
		printf("\nWord            MEANING");
		printf("\n-------------------------\n");
		printf("%s \t\t  %s\n",t->word,t->meaning);
	}
}
void  find(struct node *root,char * str)
{
	find_meaning(root,str);	
}

void inorder(struct node *t)
{
	if(t!=NULL){
		inorder(t->left);
	printf("\n%s \t\t  %s\n",t->word,t->meaning);
			inorder(t->right);
	}
}
void  print(struct node * root)
{
	inorder(root);
}

int main()
{
	int n;
	char str[1000];
	struct node * root = NULL ;
	root = insert(root,"apple","fruit") ;
	root = insert(root,"winter","season");
	
	for(;;){
		printf("\n-------------DICTIONARY--------------\n");
		
		printf("\n1.Search for a word?\n2.View the Dictionary\n3.Quit\n");
		scanf("%d",&n);
		switch(n){
			case 1: printf("\n Enter a word: ");
					scanf("%s",str);
					if(search(root,str)){
						find(root,str);
					}
					else{
						int ch;
						printf("\nWord not found in Dictionary \n Update? 1\nDont update 2\n");
						scanf("%d",&ch);
						if(ch==1){
							char mea[1000] ;
							printf("\nEnter meaning: ");
							scanf("%s",mea);
						
							root = insert(root,str,mea);
						}
					}
					break;
				case 2: 
						printf("\nWords in the dictionary with meanings");
						printf("\nWord            MEANING\n");
						printf("-------------------------\n");
						print(root);
						break;
				case 3: printf("\nClosing Dictionary...");
						break;
				default:printf("\nInvalid choice :(");
			}
	}
	
}
