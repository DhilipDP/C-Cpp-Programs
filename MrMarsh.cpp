#include<iostream>
using namespace std ;

int main(){
	int n,m ;
	cin>>n>>m;
	char rect[n][m];
	int i,j;
	for(i=0 ; i<n ; i++)
		for(j=0 ;j<m ; j++)
			cin>>rect[i][j];
	int right[n][m],down[n][m] ;
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	{
		if(rect[i][j]=='.'){
			int k;
			for(k=i ; k<n && rect[k][j]=='.' ; ++k);
				down[i][j] = k-1;
			for(k=j ; k<m && rect[i][k]=='.' ; ++k);
				right[i][j] = k-1;
		}
	}
	int ans = 0;
	for(i=0 ;i<n ; i++){
	for(j=0 ; j<m ; j++){
		if(rect[i][j]=='x')
			continue;
		for(int ti=i+1 ; ti <= down[i][j] ; ti++){
			for(int tj = j+1 ; tj<=right[i][j] ; tj++){
				if(ti <= down[i][tj] && tj<=right[ti][j])
				{
					int p = 2*((ti-i)+(tj-j));
					if(p > ans)
						ans = p;
				}
			
			}
		}
	}	
}
	if(ans==0)
		cout<<"impossible";
	else
		cout<<ans;	
}

