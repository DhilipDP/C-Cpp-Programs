#include<iostream>

using namespace std ;
void func(int arr[])
{
       int i;
       int  n = sizeof(arr)/sizeof(arr[0]);
       for(i=0; i<n ; i++)
       	cout<<arr[i]<<" ";
       cout<<endl;
}


int main()
{
       int arr[] = {0015,10024,0123,9123,00071};
       int i;
       int  n = sizeof(arr)/sizeof(arr[0]);
       for(i=0; i<n ; i++)
       	cout<<arr[i]<<" ";
       cout<<endl;
       func(arr);
       return 0;
}

