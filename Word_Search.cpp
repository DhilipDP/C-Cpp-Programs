#include<iostream>

using namespace std ;


char board[][5] = 	{{'w',	'e' ,	'L'	, 'C',	'O'} ,
					{'M',	'E',	'T' ,	'O'	,'Z'},
					{'O',	'H',	'O' ,	'C'	,'Z'},
					{'R',	'P',	'O' ,	'R'	,'A'},
					{'T',	'I',	'O' ,	'n'	,'i'} };


int visited[10][10] ;
int start_i,start_j,end_i,end_j;

bool search(string word,int i ,int j,int index)
{
	if(i<0 || i>=5 || j<0 || j>=5)
		return false  ;
	if(index==word.length()-1 && board[i][j] == word[index] ){
		end_i = i ;
		end_j = j;
		return true;
	}

	if(board[i][j] != word[index] || visited[i][j] == 1)
		return false ;
	visited[i][j] = 1;
	if(search(word,i,j+1,index+1) || search(word,i+1,j,index+1))
		return true;
	visited[i][j] = 0;
	return false;
}

int main()


{

	for(int i=0 ; i<5 ; i++){
		for(int j=0 ; j<5 ; j++){
			memset(visited,false,sizeof(visited));
			start_i = i,start_j = j;
			if(search("TOO",i,j,0))
			{
				cout<<"Start :" << start_i<< " "<<start_j<<endl;
				cout<<"End : "<< end_i << " " <<end_j<<endl;
				break;
			}
		}
	}
	
}
