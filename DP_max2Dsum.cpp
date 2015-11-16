#include<iostream>
#include<limits.h>

using namespace std ;

int kadane(int *arr,int n,int &start ,int &finish){
	int sum  = 0;
	finish = -1 ;
	int cur_start = 0;
	
	int i;
	int max_sum = INT_MIN ;
	for(i=0 ; i<n  ;i++){
		sum += arr[i] ;
		if(sum < 0){
			sum = 0;
			cur_start = i+1;
		}
		else if(sum > max_sum){
			max_sum = sum ;
			start = cur_start ;
			finish = i;
		}
	}
	if(finish!=-1)
		return max_sum ;
	else{
		for(i=0 ; i<n ; i++){
			if(arr[i] > max_sum)
				max_sum = arr[i],start=finish=i;
		}
		return max_sum;
	}
}


int findMax(int M[4][5],int row,int col){

	int max = INT_MIN ,LEFT,RIGHT,TOP,BOTTOM ;
	int temp[4] ;
	
	int l,r,i,start,finish,sum;
	for(l=0 ; l<col ; l++){
		memset(temp,0,sizeof(temp)) ;
		for(r = l ; r < col ; r++){
			for(i=0 ; i<row ; i++)
				temp[i] += M[i][r] ;
			sum = kadane(temp,row,start,finish);
			if(sum > max ){
				max = sum ;
				LEFT = l;
				RIGHT = r;
				TOP = start ;
				BOTTOM = finish;
			}
		}
	}
	for(i=TOP ; i<=BOTTOM ; i++){
		for(int j=LEFT ; j<=RIGHT ; j++)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
	return max ;
}

int main(){
	int M[4][5] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };
    cout<<findMax(M,4,5) ;

}

