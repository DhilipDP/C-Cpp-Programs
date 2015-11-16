#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define N 500
#define k 4

using namespace std ;

struct node {
	int no;
	int dis ;
};

struct edge{
	int from;
	int to;
	int dist ;
};


bool compare(const edge  &a,const edge &b){
	return a.dist < b.dist ;
}

int find(int a,int parent[]){
	if(parent[a]==a)
		return a;
	return find(parent[a],parent);
}


void union_group(int a,int b,int *parent){

	parent[b] =a ;
}
void kruskal(vector<edge> &e,int size){
	//qsort(e,e)	
	sort(e.begin(),e.end(),compare);
	vector<edge> result ;
	vector<edge> :: iterator it ;
	int parent[N+1] ;
	for(int i=1 ; i<=N ; i++)
		parent[i]=i ;
	int ed = 0 ;
	//for kruskal cond : ed<N-1
	int n = N;
	for(it=e.begin() ;  n >= k && it!=e.end()  ; it++){
		int u = find(it->from,parent);
		int v = find(it->to,parent);
		if(u!=v){
			union_group(u,v,parent);
			edge e1 ;
			e1.from = it->from ;
			e1.dist = it->dist;
			e1.to = it->to;
			result.push_back(e1);
			ed++;
			n--;
		}
	} 
	vector<edge> :: iterator r ;
	int sum = 0;
	for(r=result.begin() ; r!= result.end() ; r++){
		cout<<r->from<<" "<<r->to<<" "<<r->dist<<endl;
		sum += r->dist;
	}
	cout<<sum<<endl ;
	
}

int main(){
	FILE *fp ;
	fp = fopen("clustering .txt","r");
	vector<node > *adj = new vector<node>[N+1];
	vector<edge> edg ;
	char a[100];
	int i=1;bool first = true ;
	edge e ;
	while((fscanf(fp,"%s",a))!=EOF){
		string s(a);

		switch(i%3){
			case 0 :
				e.dist = atoi(s.c_str());
				edg.push_back(e);
				break;
			
			case 1 :
						e.from = atoi(s.c_str()) ;
						break;
			case 2 :
					e.to = atoi(s.c_str());
					break; 
				
		}
		i++;
		//edg.push_back(e);

		
		
	/*	int from ,to,dist ;
		cin>>from>>to>>dist ;
		edge e ;
		e.from = from;
		e.to = to ;
		e.dist = dist ;
		edg.push_back(e);
		struct node n1 ;
		n1.no = to ;
		n1.dis = dist ;
		adj[from].push_back(to);
		struct node n2 ;
		n2.no = from ;
		n2.dis = dist ;
		adj[to].push_back(from);
	*/}
	
	
	
/*	vector<edge> :: iterator it ;
	for(it=edg.begin() ; it!=edg.end() ; it++){
		cout<<it->from<<" "<<it->to<<" "<<it->dist<<endl;
	} */
	
	kruskal(edg,i);
	
	
//	kruskal(adj,e,n+1);
}
