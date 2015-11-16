#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

int main() {
	int t,n,i,right,down,j;
	scanf("%d",&t);
	scanf("%d",&n);
	while(t--)
	{
	 		  char a[n][n];
	 		  int b[n][n];
    		  
			  for(i=0;i<n;i++)
    		  for(j=0;j<n;j++)
  		  	  {
				b[i][j]=0;  
    		//  cin>>a[i][j];
			  }
			  
			  b[n-1][n-1]=1;
			  for(i=n-1;i>=0;i--)
			  for(j=n-1;j>=0;j--)
			  {
				 /*
				 if(i<n-1)
				 down=b[i+1][j];
				 else
				 down=0;
				 
				 if(j<n-1)
				 right=b[i][j+1];
				 else
				 right=0;
				 */
				 if(i!=n-1&&j!=n-1)
				 {
				  				   cout<<i<<" "<<j<<" "<<right<<" "<<down<<endl;
				 b[i][j]=right+down;
				 }
			  }
			  
			  for(i=0;i<n;i++)
    		 { for(j=0;j<n;j++)
  		  	  {
			cout<<b[i][j]<<" ";
			  }
			  cout<<endl;
			  }
			  getchar();
	}
return 0 ;

}
void fastread(long long int *a){
char c=0;
while(c<33)
{
c=getchar();
}
*a=0;
while(c>33){
*a=*a*10+c-'0';
c=getchar();
}
}
