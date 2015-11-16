#include<iostream>
using namespace std ;



int mul(int x,int y){
	if(y==0)
		return 0;
	if(y < 0)
		return -mul(x,-y);
	return x+mul(x,y-1);

}
int main(){
cout<<mul(13,7)<<endl;
}
