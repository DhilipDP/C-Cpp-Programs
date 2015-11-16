#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define rep(a,b,c) for(int c=a ; c<=b ; ++c)
#define pii pair<int , int>
#define vi vector<int>
#define vs vector<string>
#define vi_it vector<int> :: iterator
#define vs_it vector<string> :: iterator
#define mp(a,b) make_pair(a,b)


using namespace std ;

int size ;

int dp[2][1002][1002];

int merge(deque<int> arr,deque<int> temp,int left,int mid,int right){
	int i = left;
	int j = mid ;
	int k = left ;
	int inv = 0;
	while(i<=mid-1 && j<=right){
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else{
			temp[k++]=arr[j++];
			inv += (mid-i);
		}
	}
	while(i<=mid-1)
		temp[k++]=arr[i++];
	while(j<=right)
		temp[k++]=arr[j++];
	for(int l = left ; l<=right ; l++)
		arr[l] = temp[l];
	return inv;
}

int ms(deque<int> arr,deque<int> temp,int left,int right){
	
	int incount = 0;
	if(left < right){
		int mid =(left+right)/2;
		incount = ms(arr,temp,left,mid);
		incount += ms(arr,temp,mid+1,right);
		incount += merge(arr,temp,left,mid+1,right);
	}
	return incount;
}


int inv(deque<int> a)
{
	deque<int> temp(a.size());
	return ms(a,temp,0,a.size()-1);
}


int min(int a, int b,int c, int d)
{
	return min(a,min(b,min(c,d)));
}


int solve(vi arr,int st , int ed , deque<int> res, int n)
{
	if(st >ed)
	{
		return INT_MAX ;
	}
	
	int ans1 = dp[0][st][ed] ;
	int ans2 = dp[1][st][ed] ;
	if(ans1==-1){
		if(n==size)
		{	
			ans1 = dp[0][st][ed] =  inv(res);
		}		
		else{
			res.push_front(arr[st]);
			int a = solve(arr,st+1,ed,res,n) ;
			res.pop_front();
			res.push_front(arr[ed]);
			int b = solve(arr,st,ed-1,res,n) ;
			res.pop_front();
			ans1 = dp[0][st][ed] =min(a,b);
		}
	}
	if(ans2==-1){
		
	}
	return min(ans1,ans2);
	
	
	else{
		int a,b,c,d;
		res.push_front(arr[st]) ;
		a= solve(arr,st+1,ed,res,n+1);
		res.pop_front();
		res.push_back(arr[st]);
		b=	solve(arr,st+1,ed,res,n+1);
		res.pop_back();
		
		res.push_front(arr[ed]) ;
		c= solve(arr,st,ed-1,res,n+1);
		res.pop_front();
		res.push_back(arr[ed]);
		d = solve(arr,st,ed-1,res,n+1);
		res.pop_back();
		return min(a,b,c,d);
		
	}
	
}

int main() {
	ios :: sync_with_stdio(false);
	
	
	int t ; s(t) ;
	while(t--){
	
		int n ; s(n) ;
		vi arr(n) ;
		size = n;
		rep(0,n-1,i) s(arr[i]);
		//solve(arr);
		deque<int> res;
		p(solve(arr,0,n-1,res,0));
	}
	
	return 0;
}
