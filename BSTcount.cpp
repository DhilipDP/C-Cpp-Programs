#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	long int n;
	scanf("%d",&n);
	int arr[n+1],count=0;
	int i,root,firstleft=1,firstright=1;
	for(i=1 ; i<=n ; i++)
		arr[i]=0;
	for(i=0 ; i<n ; i++){
		int val;
		scanf("%d",&val);
		if(i==0){
			root = val;
	//		max = min = root;
			arr[val]=val;
			printf("0\n");
		}
		else{
			if(val > root){
				if(firstright){
					arr[val]=val;
					firstright=0;
					printf("%d\n",++count);
				}
				else{
				int c=0;
				for(int j=root ; j!=val ; j++){
					if(arr[j]!=0)
						c++;
				}
				arr[val]=val;
				if(val!=n && arr[val+1]!=0)
					count += (c+1);
				else
					count+=(c);
				printf("%d\n",count);
				}
				
			}
			else{
				if(firstleft){
					arr[val]=val;
					firstleft = 0;
					printf("%d\n",++count);
				}
				else{
					int c=0;
					for(int j=root ; j!=val ; j--){
						if(arr[j]!=0)
							c++;
					}
					arr[val]=val;
					if(arr[val!=1 && val-1]!=0)
						count+=(c+1);
					else
						count += c;
					printf("%d\n",count);
				}
			}
			
		}
	}
}
