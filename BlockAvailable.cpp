#include<iostream>

using namespace std ;


struct event{
	float start;
	float end ;
};
int main(){
	event e[6];
	e[0].start = 5;
	e[0].end = 5.30;
	e[1].start = 6;
	e[1].end = 6.30;
	e[2].start = 7;
	e[2].end = 8;
	e[3].start = 8;
	e[3].end = 9;
	e[4].start = 14.00;
	e[4].end = 14.30;
	e[5].start = 17;
	e[5].end = 18;
	int t =10;
	while(t--){
		float search;
	cin>>search;
//	float search = 5.25 ;
	bool blocked = false ;
	int block_event ,avail;
	int i;
	for( i=0 ; i<6 ; i++){
		if(search < e[i].end && search >=e[i].start){
			cout<<"Blocked";
			block_event = i;
			blocked = true ;
			break;
		}
		if(search >= e[i].end)
			avail = i;
	}
	if(blocked){
		int i = block_event ;
		if(i==5)
			cout<<"\nWill be available at : "<<e[i].end<<endl;
		else{
	//	cout<<"hi"<<e[i+1].start<<"  "<<e[i].end;
		while(true){
			if(e[i+1].start > e[i].end){
			
			cout<<"\nWill be available at : "<<e[i].end<<endl;
			break;
		}	
			i++;
		}
	}
	}
	else{
		avail = avail == i ? avail : avail+1;
		cout<<"Available !"<<"\nWill be blocked at : "<<e[avail+1].start<<endl;
	}
}
}

