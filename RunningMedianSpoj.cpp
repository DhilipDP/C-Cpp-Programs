#include<list>
#include<stdio.h>
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)

using namespace std; 
int main(){
	int n,count=0;
	list<int> l;
	list<int> :: iterator mid,pre,next,temp ;
	mid = l.begin();
	while((s(n))!=EOF){
		if(n==0){
			l.clear();
			printf("\n");
			mid = l.begin();
			count = 0;
		}
		else if(n==-1){
			p(*mid);
			temp = mid ;
			mid ++;
			next = mid ;
			mid --;
			if(mid!=l.begin())
				mid--;
			pre = mid ;
			l.erase(temp);
			if(count & 1)
				mid = pre;
			else
				mid = next;
			count--;
		}
		else{
			l.push_back(n);
			count++;
			if(count & 1)
				mid++;
		}
	}
}
