#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

#define SIZE 875715
using namespace std ;

struct time{
	int no;
	int val;
};

unsigned long t=0;
int s;

//int leader[SIZE];

vector<time> f ;
	
int nodes ;
void DFS(vector<int> *g,int i,bool visited[]){
	visited[i]=true ;
//	leader[i]=s;
	vector<int> :: iterator it ;
	for(it = g[i].begin() ; it!=g[i].end() ; it++){
		if(!visited[*it]){
			cout<<"\nIn DFS traversing : "<<*it;
			DFS(g,*it,visited);
			nodes++;
		}
	}
	t++;
//	f[i].val=t;
//	f[i].no=i;
	struct time ti ;
	ti.no = i ;
	ti.val = t ;
	f.push_back(ti);
}

void DFS_Loop(vector<int> *g){
	bool visited[SIZE];
	memset(visited,false,sizeof(visited));
	for(int i=SIZE-1 ; i>=1 ; i--){
		if(!visited[i]){
			cout<<"Traversing :" << i<<endl;
		//	s=i;
			DFS(g,i,visited);
		}
	}
}

bool compare(const time &a,const time &b)
{
//	cout<<"hllo";
return a.val > b.val ;
}


int arr[SIZE];
int sz=0;
void DFS_Loop_final(vector<int> *g){
	sort(f.begin(),f.end(),compare);
	vector<time> :: iterator it; 
	cout<<endl;
/*	for(it = f.begin() ; it!=f.end() ; it++){
			cout<<it->no<<" "<<it->val<<endl;
		}
	cout<<endl;  */
//	for(int i=0 ; i<10 ; i++)
//		cout<<f[i].val<<" ";
	bool visited[SIZE];
	int j=0;
	memset(visited,false,sizeof(visited));
	
//	vector<time> ::  iterator it ;
	int k = 0 ;
	for(it = f.begin() ; k<SIZE-1 ; it++,k++){
	//	cout<<it->no<<endl;
		for(int i=it->no ; i>=1 ; i--,j++){
		if(!visited[i]){
			cout<<"Traversing: "<<i<<endl;
			s=i;
			nodes = 0;
			DFS(g,i,visited);
			arr[sz++]=nodes+1 ;
		}
	}
//	cout<"hi";
	}
}

void stronglyConnected(vector<int> *gra,vector<int> *gra_rev){
	cout<<"Running loop on rev"<<endl;
	DFS_Loop(gra_rev);
//	for(int i=1 ; i<=9 ; i++)
//		cout<<f[i]<<" ";
	cout<<"Running loop on norml"<<endl;
	DFS_Loop_final(gra);
	//	cout<<"hi";
}

int mcompare(const void * a,const void *b)
{
//	cout<<"COmparing: "<<*(int *)a<<" "<<*(int *)b;
	return (*(int*)b-*(int *)a);
}
int main(){
	struct time e ;
	e.no = 0;
	e.val = 0 ;
	f.push_back(e) ;
	FILE *fp ;
	fp = fopen("SCC.txt","r");
	vector<int> *gra = new vector<int>[SIZE]; 
	vector<int> *gra_rev = new vector<int>[SIZE];
	char a[100];
	char b[100];
	int from,to;
	while((fscanf(fp,"%s",a))!=EOF){
	//cin>>to;
	fscanf(fp,"%s",b);
		string f(a),t(b);
		cout<<a<<" "<<b<<endl;
		from = atoi(f.c_str());
		to = atoi(t.c_str());
		gra[from].push_back(to);
		gra_rev[to].push_back(from);
	}
	
	int i,j ;
	vector<int> :: iterator it ;
	for(i=1 ; i<=12; i++){
		for(it = gra_rev[i].begin() ; it!=gra_rev[i].end() ; it++){
			cout<<i<<" : "<<*it<<endl;
		}
	}
	cout<<"Going to fun:"<<endl;
	stronglyConnected(gra,gra_rev);
	cout<<"Returning from fun: "<<endl;
//	cout<<"hi";
	qsort(arr,sz,sizeof(int),mcompare);
	for(int i = 0 ; i<sz ; i++)
		cout<<arr[i]<<endl;
	while(sz < 5)
{	

		cout<<0<<endl;
		sz++;

	}
}
