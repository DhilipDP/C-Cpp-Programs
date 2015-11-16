#include<iostream>
using namespace std ;

class Debug{
	private:
	    int value = 0x1233;
	public :
		 virtual void show(){
			cout<<"Welcome to Debugging\n";
		}
};


class Kurukshetra : public Debug{
	int value = 5;
	public :
	  void show(){
			cout<<"Welcome to K!15\n";
		}
};

int main(){
	Kurukshetra d;
	d.show();
	cout<<sizeof(Debug)<<" "<<sizeof(Kurukshetra)<<endl;
	return 0;
}
