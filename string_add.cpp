#include<stdio.h>
#include<string.h>
void strreverse(char *a)
{
int i,j;
char temp;
int l=strlen(a);
j=l-1;
for(i=0;i<(l/2);i++,j--)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
a[l]='\0';
//printf("\n %s\n",a);
} 
int max(int l1,int l2)
{
int res;
res=(l1>l2)?l1:l2;
return res;
} 
int main()
{
	char c1[100]="110";
	strreverse(c1);
	printf("%s\n",c1);
	
char a[100],b[100],c[100];
int i,sum=0,carry=0,m,n,l1,l2;
printf("Enter a and b:\n");
scanf("%s%s",a,b);
l1=strlen(a);
l2=strlen(b);
strreverse(a);
strreverse(b);
for(i=0;i<max(l1,l2);i++)
{

m= i<l1 ?(a[i]-'0'):0;
n= i<l2 ?(b[i]-'0'):0;

sum=(carry+m+n)%10;
carry=(carry+m+n)/10;
printf("%d %d\n",sum,carry);
c[i]=sum+'0';
}
//printf("\n");
if(carry!=0) 
{
c[i++]=carry+'0';

}
c[i] = '\0';
printf("\n%s",c);
strreverse(c);
printf("\nTha answer is:%s\n",c);
}
