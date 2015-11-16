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


vector<ll int> num ; 
int size ;
ll int convert()
{
	ll int ans = 0;
	rep(0,size-1,i)
		ans = (ans * 10) + num[i];
	return ans ;
}

int main()

{
	int j=0,t ; s(t) ;
	
	while(t)
	{
		num.clear();
		size = 0;
		bool flag = false;
		char name[21] ;
		cin.getline(name,21);
		if(j==0) {
		j++;
		continue;
		}
		t--;
		for(int i=0 ; i<strlen(name) ; i+=2)
			num.push_back(name[i]-'0');
		sort(num.begin() , num.end());
		size = num.size();
		ll int val ;
		sll(val);
		ll int res =0;
		do{
			res = convert();
			printf("%lld\n",res);
			if(res%val==0)
			{
				ll int v = res/val;
				printf("%lld = %lld * %lld\n",res,val,v);
				flag = true;
				break;
			}
		}while(next_permutation(num.begin() , num.end()));
		if(!flag)
			cout<<"Impossible"<<endl;
			j=0;
	}	
	
	return 0;
}
