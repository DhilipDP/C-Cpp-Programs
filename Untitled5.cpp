#include<iostream>
#include<queue>
#include<stdlib.h>
#define max 100000
using namespace std;

class node {
public:
int number;
int height;
int stones;
int parent;
int child;
node *a[max];
public: node(){
height=0;
parent=stones=child=0;

}
};


int main(){
int t,n,k;
int a,b,c,d;
cin>>t;
while(t--)
{
 		  
cin>>n;
cin>>k;
class node *array=new node[n+1];
array[1].stones=k;
for(int i=1;i<n+1;i++)
array[i].number=i;


for(int i=1 ; i<n ; i++){
cin>>a>>b;
array[a].a[array[a].child]=&array[b];
array[a].child++;

	if(array[a].height<array[b].height+1)
	array[a].height=array[b].height+1;
	c=a;
	array[b].parent=a;
	while(array[c].parent!=0)
	{
	d=array[c].parent;
	if(array[d].height<array[c].height+1)
	array[d].height=array[c].height+1;
	else 
	break;
	 	c=d;			
	}
}
if(array[1].height%2==0&&k%2==1)||(array[1].height%2==1&&k%2==0))
cout<<"Babri";
else
cout<<"Eli";
cout<<endl;
/*
for(int i=1;i<n+1;i++)
{
cout<<i<<" "<<array[i].height<<" "<<array[i].parent<<endl;
for(int j=0;j<array[i].child;j++)
cout<<array[i].a[j]->number<<" "<<endl;
}
*/
/*
bool found,elis=true;
while(1)
{
found=false;
 		for(int i=1;i<n+1;i++)
 		{
				if(array[i].stones!=0&&array[i].height!=0)
		 		{
				
					int stones=array[i].stones;
					int ans=0;
					for(int j=0;j<array[i].child;j++)
					{
					if((array[i].a[j]->height%2==0)&&(stones%2==1)||(array[i].a[j]->height%2==1)&&(stones%2==0))
				{	ans=j;
					break;
				}
					}
					array[i].stones--;
					array[i].a[ans]->stones++;
				


					if(elis)
					elis=false;
					else
					elis=true;
					found=true;
					break;		
				}
		}
		
		if(found==false)
		{
		 		//		if(!elis)
		 				cout<<"Eli"<<endl;
		 		//		else
		 		//		cout<<"Babri"<<endl;
		 				break;
		}
}*/
}
return 0;
}


