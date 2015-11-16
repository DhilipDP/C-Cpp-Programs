#include<stdio.h>
#include<stdlib.h>
struct stud{
	int roll;
	int marks;
	struct stud *next;
};

void getnodedata(struct stud *s)
{
	printf("enter stud details::\n");
	scanf("%d%d",&s->roll,&s->marks);
}
struct stud* formlist(struct stud **head)
{
	int i; 
	for(i=0;i<3;i++){
			struct stud* s=(struct stud*)malloc(sizeof(struct stud));
		getnodedata(s);
		if(*head==NULL)
		{
			*head=s;
			s->next=NULL;
		}
		else{
		struct stud *p=*head;
		while(p->next!=NULL)
			p=p->next;
		p->next=s;
		s->next=NULL;
		}
	}
	return *head;
}
void traverse(struct stud *head)
{
	printf("ROLLNO		MARKS\n");
	struct stud *p=head;
	while(p!=NULL)
	{
		printf("%d		%d\n",p->roll,p->marks);
		p=p->next;
	}
}
int count(struct stud *head)
{
	int c=0;
	struct stud *p=head;
	while(p!=NULL)
	{
		c++;
		p=p->next;
	}
	return c;
}
void findmid(struct stud *head)
{
	struct stud *p=head;
	struct stud *fast=p;
	struct stud *slow=p;
	if(p!=NULL)
	{
		while(fast!=NULL && fast->next!=NULL)
		{
			fast=fast->next->next;
			slow=slow->next;
		}
		printf(" %d %d ",slow->roll,slow->marks);
	}
}
void findlargest(struct stud *head)
{
	struct stud *max=head;
	struct stud *t=head->next;
	while(t!=NULL)
	{
		if(max->marks<t->marks)
			max=t;
		t=t->next;
	}
	printf("maximum %d %d ",max->roll,max->marks);
	
}
void formsortedlist(struct stud **head)
{
	struct stud *i=*head;
	struct stud *p=*head;
	struct stud *j=(*head)->next;
	while(i!=NULL)
	{
		j = i -> next ;
		while(j!=NULL)
		{
			if(i->roll>j->roll)
			{
				int temp = i->roll ;
				i->roll = j->roll;
				j->roll = temp;
			}
			j=j->next;
		}
		i=i->next;
	}
	//traverse(*head);
/*	while(p!=NULL)
	{
		printf("%d %d",p->roll,p->marks);
		p=p->next;
	}*/
}
void findavg(struct stud *head)
{
	struct stud *p=head;
	int avg=0;
	int c=0;
	while(p!=NULL)
	{
		avg=avg+p->marks;
		p=p->next;
		c++;
	}
	printf("\naverage mark is %d ",avg/c);
}
void countfailures(struct stud *head)
{
	struct stud *p=head;
	int c=0;
	while(p!=NULL)
	{
		if(p->marks<50)
		{
			c++;
		}
		p=p->next;
	}
	printf("no of failures %d ",c);
}


struct stud * middle_element(struct stud * head){
	int  no_of_elements = count(head);
	int mid = no_of_elements/2;
	struct stud * p = head ;
	int i=0;
	while(p!=NULL && i<mid){
		i++;
		p=p->next;
	}
	return p;
}
int  main()
{
	struct stud *head=NULL;
	struct stud *b=formlist(&head);
	printf("%d %d\n",b->roll,b->marks);
	traverse(head);
	printf("count of elements is %d\n",count(head));
	findmid(head);
	findlargest(head);
	formsortedlist(&head);
	traverse(head);
	findavg(head);
	countfailures(head);
	struct stud * mid = middle_element(head);
	printf("Middle student : %d %d\n",mid->roll,mid->marks);
}
