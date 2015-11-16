#include<iostream>
#include<limits.h>
using namespace std ;



int maxNonRepeating(string str){
		int n = str.length() ;
		int cur_length = 0;
		int max_length = 0 ;
		int visited[256]  ;
		for(int i=0 ; i<256 ; i++)
			visited[i] = -1 ;
		int temp_start =0;
		int start = 0;
		for(int i=0 ; i<n ; i++){
			if(visited[str[i]]==-1)
			{	cur_length++;
			}
			else{
				int pre = visited[str[i]];
				if(i - cur_length <= pre)
				{
					if(cur_length > max_length)
						max_length = cur_length , start =  temp_start;
					cur_length = i-pre;
					temp_start = pre+1;
				}
				else
					cur_length++;
			}
			visited[str[i]] = i;
		}
		if(cur_length > max_length)
			max_length = cur_length,start = temp_start ;
		for(int i=start ,j=0 ; j<max_length ; j++,i++)
			cout<<str[i];
		cout<<endl;
		return max_length; 
}


int main() {
	string str = "ABCDEFGH" ;
	cout<<maxNonRepeating(str);
}
