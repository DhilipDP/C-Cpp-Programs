#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std ;

class Test
{
    static int x;
    int *ptr;
    int y;
    
    void my_fun() { 
   // cout<<x<<endl;
    }
    
    virtual void fun()
    {
    //	cout<<"virtual "<<x<<endl;
    }
};
 

struct my_struct
{
	int integer ;
	char character ;	
};
int main()
{
	struct my_struct  node ;
//	printf("%d",sizeof(node));
	
	
    Test t;
    cout << sizeof(t) << " ";
    cout << sizeof(Test *) <<endl;
	
		
	char my_name[]= "sync" ;
	char *ptr = my_name ;
	int length = strlen(my_name) ,i ;
	for(i=0 ; i<length ;  i++)
		printf("%s ",my_name+i),ptr++;
	printf("%s",ptr);
}
