#include<stdio.h>
int min(int a,int b)
{
return a>b?b:a;
}

int max(int a,int b)
{
return a>b?a:b;
}

int g(int i, int j,long int *a) {
    int sum = 0;
    for (int k = min(i, j) + 1; k <= max(i, j); k = k + 1)
        sum = sum + a[k];
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    long int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    int min=999999,temp;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(i!=j)
    {
            long int d=g(i,j,a);
            temp=(i-j)*(i-j)+d*d;
            if(temp<min)
            min=temp;
    }
    printf("%d",min);
}
