#include<iostream>
#include<bitset>
#define MAXSIZE 256
#define ROW 5
#define COL 6
using namespace std ;


void print_matrix(int A[],int R,int C ){
	for(int i=0 ; i<R; i++){
		for(int j=0 ; j<C ; j++)
			cout<<(*(A + i*C + j))<<" ";
	cout<<endl;
	}
}


void swap(int &a,int &b){
	int temp = a ;
	a = b;
	b = temp;
}
void Transpose_in_place(int A[]){
		bitset<MAXSIZE> b ;
		int size = ROW*COL-1;
		b.reset();
		b[0]=b[size]=1;
		int i=1 ;
		while(i < size){
			int t= A[i];
			cout<<"t: "<<t<<endl<<"cyclestart: "<<i<<endl;
			int cycle_start = i,next ;
			do{
				next = (i * ROW)%size;
				cout<<"next value: "<<next<<" element :" <<A[next]<<endl;
				cout<<"Swapping: "<<A[next]<<" "<<t<<endl;
				swap(A[next],t);
				cout<<endl;
				print_matrix(A,2,3);
				b[i]=1;
				i=next;
			}while(i != cycle_start);
			for(i=1 ; i<size && b[i] ; i++);
			print_matrix(A,ROW,COL);
		}
}

int main(){
	int mat[ROW][COL] = {{1,2,3,4,5,6},
						{7,8,9,10,11,12},
						{13,14,15,16,17,18},
						{19,20,21,22,23,24},
						{25,26,27,28,29,30}};
	//single dimension
	int A[ROW*COL] ,k=0;
	for(int i=0 ; i<ROW ; i++)
		for(int j=0 ; j<COL ; j++)
			A[k++] = mat[i][j];
		
	print_matrix(A,ROW,COL);
	Transpose_in_place(A);
	cout<<"\nTransposing!\n\n";
	print_matrix(A,COL,ROW);
					
}
