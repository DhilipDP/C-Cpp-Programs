#include <stdio.h>
#include <string>



	struct node{
		char * word;
		char * meaning;
		struct node *left;
		struct node *right;
	};
	
	

struct node * insert(struct node  * root,char * str,char * mea)
{
	node * p, *q;
	node *n=new node;
	n->word=str;
	n->meaning=mea;
	n->left=n->right=NULL;
	if(root==NULL){
		root=n;
		printf("Inserted %s into the dictionary\n",str);
	}
	else{
		p=q=root;
		while(p!=NULL){
			q=p;
			if(str < p->word)
				p=p->left;
			else if(str > p->word)
				p=p->right;
			else 
				break;
		}
		if(str < q->word){
			printf("Inserted %s into the dictionary\n",str);
			q->left=n;
		}
		else if(str > q->word){
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
	else if(str < t->word)
		return search_element(t->left,str);
	else if(str > t->word)
		return search_element(t->right,str);
	else if(str == t->word)
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
	 if(str < t->word)
		find_meaning(t->left,str);
	else if(str > t->word)
		find_meaning(t->right,str);
	else if(str==t->word){
		printf("\nWord Found!!\n ");
		printf("\nWord            MEANING");
		printf("-------------------------");
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
	printf("%s \t\t  %s\n",t->word,t->meaning);
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
	char mea[1000];
	struct node * root = NULL ;
	for(;;){
		printf("\n-------------DICTIONARY--------------\n");
		printf("\n1.Search for a word?\n2.View the Dictionary\n3.Quit\n");
		scanf("%d",&n);
		switch(n){
			case 1: printf("\n Enter a word: ");
					scanf("%s",&str);
					if(search(root,str)){
						find(root,str);
					}
					else{
						printf("DSd");
						int ch;
						printf("\nWord not found in Dictionary \n Update? 1\nDont update 2");
						scanf("%d",&ch);
						if(ch==1){
							printf("\nEnter meaning: ");
							scanf("%s",mea);
							root = insert(root,str,mea);
						}
					}
					break;
				case 2: printf("\nWords in the dictionary with meanings");
						printf("\nWord            MEANING");
						printf("-------------------------");
						print(root);
						break;
				case 3: printf("\nClosing Dictionary...");
						break;
				default:printf("\nInvalid choice :(");
			}
	}
	
}
