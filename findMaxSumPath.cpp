#include<iostream>
using namespace std ;


void findSumPath(int arr[],int path[],int i,int root,int cur_sum,int target){
	if(arr[root]==-1 )
	{
	//	cout<<cur_sum<<endl;
		return ;
	}
	path[i++] = arr[root];
	cur_sum += arr[root];
	if(2*root >= 15 ){
			if(cur_sum == target)
			for(int j=0 ; j<i ; j++)
					cout<<path[j]<<" ";
				cout<<endl;
	}

	else if(arr[root]!=-1 ){
		findSumPath(arr,path,i,2*root,cur_sum,target);
		findSumPath(arr,path,i,2*root+1,cur_sum,target);
	}
	
}
int main(){
	int sum=40 ,l;
	int no_of_nodes =  15;
	int arr[] = { 0,10 ,11, 13, -1, 15, 28, 6 ,-1, -1, 8, 4, -1, 9, 11, -1};
	int *path = new  int [no_of_nodes];
	int cur_sum=0;
	int i=0;
	findSumPath(arr,path,i,1,cur_sum,sum);
}
