#include<iostream>
#include<algorithm>
using namespace std;

int compare(const void * a,const void * b){
	return (int *)a - (int *)b;
	
}
int main(){
	char c='y';
	int arr[]={2,6,9,1,3,10};
	qsort(arr,7,sizeof(int),compare);
	for(int i=0 ; i<7 ; i++)
		cout<<arr[i]<<" ";
	while(c!='n'){
	cout<<endl;
	int choice;
	cout<<"\nEnter ur choice \n(1).Triangle \n2.Square \n3.Circle \n4.Rectangle\n5Quit:\n";
	cin>>choice;
	switch(choice){
		case 1 : float b,h;
					cin>>b>>h;
					float ar;
					ar = 0.5*b*h;
				cout<<ar;
				break;
		case 2 : int a;					cin>>b;
				cout<<a*a;
				break;
		case 3 : float r;
				cin>>r;
				cout<<3.14 * r * r;
				break;
		case 4 : int l,d;
					cin>>l>>d;
				cout<<l*d;
				break;
			case 5 : c='n';
	
	}
	}	
	return 0;
}
