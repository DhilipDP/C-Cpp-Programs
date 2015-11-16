#include<iostream>

#include<stdio.h>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int i,root;
	int *left,*right,firstleft=true,firstright=true,leftpos,rightpos=0,count=0;
	for(i=0 ; i<n ; i++){
		int val;
		scanf("%d",&val);
		if(i==0){
			root = val;
			left = new int[root+1];
			right = new int[n-root+2];
			leftpos = root;
			right[rightpos]=left[leftpos]=root;
					
		}
		else if(val > root){
			if(firstright){
				right[++rightpos]= val;
				firstright = false;
				count++;
			}
			else{
			int c=0;
			for(int i=0 ; i<=rightpos ; i++){
				if(right[i] < val)
					c++;
				else{
					c++;
					int temp = right[i];
					for(int j=i+1 ; j<=rightpos && right[j] < temp  ; j++)
						c++;
					break;
				}
			}
			right[++rightpos]=val ;
			count += c;
			}
		}
		else{
			if(firstleft){
				left[--leftpos] = val;
				firstleft = false;
				count++; 
			}
			else{
			int c = 0;
			for(int i=root ; i>=leftpos ; i--){
				if(left[i] > val)
					c++;
				else{
					c++;
					for(int j=i-1 ; j>=leftpos && left[j] < val ; j--)
						c++;
					break;
				}
			}
			left[--leftpos]= val;
			count += c;
		}
		}
		
		printf("%d\n",count);
	}
}
