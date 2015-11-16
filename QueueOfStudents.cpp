//#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
struct student{
	char name[20];
	int roll;
	int marks;
};
struct queue{
	int f,r;
	struct student s[SIZE];
};
struct queue *createq()
{
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
	q->f=q->r=0;
//	q->s = malloc(sizeof(student) * SIZE);
	return q;
}
void insert(struct queue *q,struct student s)
{

	q->s[q->r] = s;
	q->r++;
	printf("inserted\n");
}
//void delete(struct queue *q)
int main()
{
	struct queue *q=createq();
	printf("enter student details\n");
	for(int i=0;i<3;i++)
	{
		student s ;
		scanf("%s%d%d",s.name,&s.roll,&s.marks);
		insert(q,s);
	}
//	printf("%s ",q->s[q->f].name);
	return 0;
}
