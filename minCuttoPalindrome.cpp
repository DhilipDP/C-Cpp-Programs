#include<iostream>

using namespace std ;

bool isPalindrome(const string& str, int begin, int end)
{
    for(int i = begin; i < end - (i - begin); ++i)
    {
        if(str[i] != str[end - (i - begin)])
            return false;
    }

    return true;
}


void print(int arr[],int n){
	int i ;
	for(i=0 ; i<n ; i++)
		cout<<arr[i]<<" ";
	cout<<endl ;
}


int minSplit_2(const string& str)
{
    int length = str.size();
    int* split = new int[length];
    for(int i = 0; i < length; ++i)
        split[i] = i;

	print(split,length);
    for(int i = 1; i < length; ++i)
    {
        if(isPalindrome(str, 0, i))
        {
            split[i] = 0;
            continue;
        }

        for(int j = 0; j < i; ++j)
        {
            if(isPalindrome(str, j + 1, i) && split[i] > split[j] + 1)
                split[i] = split[j] + 1;
        }
        	print(split,length);
    }

    int minSplit = split[length - 1];
    delete[] split;
    return minSplit;
}
int main(){
	string a = "abbab";
	cout<<minSplit_2(a);
}
