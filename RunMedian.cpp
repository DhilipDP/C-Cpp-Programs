#include<stdio.h>
#define SIZE 100001
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)

int main(){
	int n;
	int *arr = new int[SIZE];
	int size =0,i;
	while((s(n))!=EOF){
		if(n!=0){
			if(n==-1 && size!=0){
			//	p(size);
				int med ;
				med = size & 1 ? size/2+1 : size/2 ;
				p(arr[med]);
				for(int k=med ; k<size ; k++)
					arr[k] = arr[k+1];
				size--;
				//for(int j=1 ; j<=size ; j++)
			//p(arr[j]); 
				
			}
			else{
				size++;
				arr[size] = n ;
				
			}
		}
		else{
			delete []arr;
			size = 0;
		}
		
	}
}
