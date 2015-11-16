#include<iostream>
#include<vector>
#include<algorithm>


using namespace std ;



struct line
{
	int height ;
	int num_taller ;
};

struct comp{
	bool operator()(const struct line &a ,const struct line &b){
		return a.height < b.height ;
	}
};


vector<int> findOrder(vector<int> height,vector<int> front)
{

	int n = height.size() ;
		vector<int> res (n);
	if(n==0)
		return res ;
	
	line arr[n] ;
	for(int i=0 ; i<n ; i++)
	{
		arr[i].height = height[i];
		arr[i].num_taller = front[i] ;
	}
	sort(arr,arr+n,comp());
	vector<int> hash ;
	for(int i=0 ; i<n ;i++)
		hash.push_back(i);
	for(int i=0 ; i<n ; i++)
	{
		int taller = arr[i].num_taller ;
		res[hash[taller]] = arr[i].height ;
		hash.erase(hash.begin() + taller);
	}	
	return res;
}

int main()
{
	int hei[]  = {5,3,2,6,1,4} ;
	int frt[] = {0,1,2,0,3,2} ;
//	int hei[] = {2,1,6,4,5,3} ;
//	int frt[] = {0,1,0,1,1,3} ;

//	int hei[] = {1,2,3,4};
//	int frt[] = {0,0,0,0} ;
	int n = sizeof(hei)/sizeof(hei[0]);
	vector<int> heights = vector<int>(hei,hei+n) ;
	vector<int> front = vector<int>(frt,frt+n);
	vector<int> line = findOrder(heights,front) ;
	for(vector<int> :: iterator it = line.begin() ; it != line.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;
}
