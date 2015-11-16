#include<stdio.h>
#include<limits.h>

using namespace std;

long int arr[10000];
long int boy_cur_i=1;
long int boy_cur_j=1;
long int girl_cur_i;
long int girl_cur_j=1;
long int min_i ;
long int min_j ;
long int boy_gain = 0;
long int girl_gain = 0;

void find_min(long int n,long int m){
	long int min = INT_MAX;
	for(long int i=1 ; i<=n ; i++){
		for(long int j =1 ; j<=m ; j++){
			if(arr[i][j] < min)
				min_i = i;
				min_j = j;
		}
	}
}


long int getGain(int x){
	switch(x){
		case 1: return arr[boy_cur_i][boy_cur_j];
		case 2: return arr[girl_cur_i][girl_cur_j];
	}
}

void boy_to_min(){
	int i_dis = min_i - boy_cur_i;
	int j_dis = min_j - boy_cur_j;
	int g;
	if(i_dis <= j_dis){
		boy_cur_i ++;	
	}
	else{
		boy_cur_j++;
	}
	if(boy_cur_i &&  boy_cur_j != girl_cur_i && girl_cur_j){
			g = getGain(1);
			boy_gain += g;
		}
	else if(boy_cur_i &&  boy_cur_j != girl_cur_i && girl_cur_j && (boy_cur_i != min_i || boy_cur_j != min_j))		{
			boy_cur_i --;
			boy_gain -=g
			boy_to_min();
		}
	
}


void girl_to_min(){
	int i_dis = min_i - girl_cur_i;
	int j_dis = min_j - girl_cur_j;
	int g;
	if(i_dis <= j_dis){
		girl_cur_i --;	
	}
	else{
		girl_cur_j++;
	}
	if(boy_cur_i &&  boy_cur_j != girl_cur_i && girl_cur_j){
			g = getGain(1);
			boy_gain += g;
		}
	else if(boy_cur_i &&  boy_cur_j != girl_cur_i && girl_cur_j && (boy_cur_i != min_i || boy_cur_j != min_j))		{
			girl_cur_i --;
			boy_gain -=g
			girl_to_min();
		}
	
}
int main(){
	long int m,m;
	scanf("%ld%ld",&n,&m);
	long int i,j;
	girl_cur_i=n;
	for(i=1 ; i<=n ; i++)
		for(j=1 ; j<=m ; j++)
			scanf("%ld",&arr[i][j]);
	boy_gain += arr[1][1];
	girl_gain += arr[n][1];
    find_min(n,m);
    while(1){
	if(boy_cur_i != mid_i && boy_cur_j != mid_j)
   			 boy_to_min();
	if(girl_cur_i != mid_i && girl_cur_j != mid_j)
  			  girl_to_min();
	}
	cout
	return 0;
}
