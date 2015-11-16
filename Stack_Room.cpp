#include<iostream>
#include<stdio.h>
#define MAXSIZE 10000
#define  print(a) printf("%d" ,a)

using namespace std ;

char  room[MAXSIZE][100];
int top = -1 ;

bool is_empty(){
	if(top==-1)
		return true;
	return false;
}

bool is_full(){
	if(top==MAXSIZE-1)
		return true;
	return false ;
}

void push(char name[]){
	if(is_full()){
//		cout<<"Room  is full";
		return ;
	}	
//	cout<<"Pushing "<<name<<endl;
	top++;
	strcpy(room[top],name);
}

char* pop(){
	if(is_empty()){
//		cout<<"Room is empty"<<endl;
		return "";
	}
//1	cout<<"Popping : "<<room[top]<<endl;
	char n[100];
	strcpy(n,room[top]);
	top--;
	return n;
}

void print_room(){
	for(int i=0 ; i<=top ; i++)
		cout<<room[i]<<endl;
}

int main(){
//cout<<"Enter number of people";
	int n;
	cin>>n;
	while(n--){
		char st[100];
		cin>>st;
		if(strlen(st)!=7)
			push(st);
		else{
			int s=0;
			char saved[MAXSIZE][100];
			char* popped;
			int no_of_popped = 0;
			while(no_of_popped != 2){
				popped = pop();	
				if(strcmp(popped,"")==0)
					break;
				if(strlen(popped)==7){
					strcpy(saved[s++],popped);
				}		
				else
					no_of_popped++;
			}
			for(int i=0 ; i<s ; i++)
					push(saved[i]);
			push(st);
		}
	}
	cout<<"Room contains:\n";
	print_room();
	return 0;
}
