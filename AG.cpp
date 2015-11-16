


#include<stdio.h>
#include<iostream>
using namespace std;
#define SIGMA 256
#define XSIZE 100

void preBmBc(unsigned char *x, int m, int bmBc[]) {
    int i;
    for (i = 0; i < SIGMA; ++i) bmBc[i] = m;
    for (i = 0; i < m - 1; ++i) bmBc[x[i]] = m - i - 1 ,cout<<x[i]<<":"<<bmBc[x[i]]<<endl;
}
 
 
void suffixes(unsigned char *x, int m, int *suff) {
    int f, g, i;
    suff[m - 1] = m;
    g = m - 1;
    for (i = m - 2; i >= 0; --i) {
        if (i > g && suff[i + m - 1 - f] < i - g)
            suff[i] = suff[i + m - 1 - f];
        else {
            if (i < g) g = i;
            f = i;
            while (g >= 0 && x[g] == x[g + m - 1 - f]) --g;
            suff[i] = f - g;
        }
    }
}

void preBmGsAG(unsigned char *x, int m, int bmGs[], int suff[]) {
    int i, j;
    suffixes(x, m, suff);
    cout<<"Suff"<<endl;
    for(int i=0 ; i<m ; i++)
    	cout<<suff[i]<<" ";
    cout<<endl;
    cout<<"bmgs"<<endl;
    for (i = 0; i < m; ++i) bmGs[i] = m;
    j = 0;
    for (i = m - 1; i >= 0; --i){
    	cout<<"i : "<<i<<endl;
        if (suff[i] == i + 1){
        	cout<<"if satisfied "<<endl;
            for (; j < m - 1 - i; ++j){
            	cout<<"j: "<<j<<endl;
                if (bmGs[j] == m)
                   bmGs[j] = m - 1 - i,cout<<bmGs[j]<<endl;
               }
            }
               }
    for (i = 0; i <= m - 2; ++i)
        bmGs[m - 1 - suff[i]] = m - 1 - i;
}



int search(unsigned char *x, int m, unsigned char *y, int n) {
    int i, j, k, s, shift, count;
    int bmGs[XSIZE], skip[XSIZE], suff[XSIZE], bmBc[SIGMA];
  
    /* Preprocessing */
    preBmGsAG(x, m, bmGs, suff);
    cout<<"BmGs"<<endl;
    for(int i=0 ; i<m ; i++)
    	cout<<bmGs[i]<<" ";
    cout<<endl;
    preBmBc(x, m, bmBc);
    memset(skip, 0, m*sizeof(int));
  
    /* Searching */
    count = 0;
    j = 0;
    cout<<"searching";
   	while (j <= n - m) {
   		cout<<"j: "<<j<<endl;
        i = m - 1;
        while (i >= 0) {
        	cout<<"i: "<<i<<endl;
            k = skip[i];
            s = suff[i];
            if (k > 0)
                if (k > s) {
                   if (i + 1 == s)
                      i = (-1);
                   else i -= s;
                   break;
                }
                else {
                    i -= k;
                    if (k < s) break;
                }
            else {
                if (x[i] == y[i + j]) --i;
                else break;
            }
        }
        if (i < 0) {
//            OUTPUT(j);
count++;
  	cout<<"success"<<j<<endl;
            skip[m - 1] = m;
            shift = bmGs[0];
        }
     
	    else {
            skip[m - 1] = m - 1 - i;
            cout<<"bmgs[i]"<<bmGs[i]<<" "<<bmBc[y[i + j]]- m + 1 + i<<endl;
            shift = max(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
        }
        cout<<"shift: "<<shift<<endl;
        j += shift;
        memcpy(skip, skip + shift, (m - shift)*sizeof(int));
        memset(skip + m - shift, 0, shift*sizeof(int));
       // for(int i=0 ; i<sizeof(skip) ; i++)
     
    }
    return count;
}


int main(){
//	string s="AUDRYBERNITAEATVIVANBROOKSEATJENIEATMICHALELASANDRALATIAEATLIDIAEATDEANDRAEATSYBILEATMONROEEATLATRISHAALTAEATDERICKEATROSANNLEVILIBBYKIRSTENCHARLESEATELLYNEATJANEEEATSTASIAEATJULIETTARANDIEATNORBERTSAGEEATARACELIKATINAMERNAEATISAIASWINNIEEATARLETHAEATMILOCAMIEEATANNABELEATLEANORABERTHASYBLECHANAEATREAGANERICKVALENTINAEATDORETHEASEBASTIANKRISROBERTAEATIVONNEEATAI";
	//cout<<s.length();

	unsigned char * x = (unsigned char *)"nananan";
	unsigned char * y = (unsigned char *) "dunandunananand";
cout<<	search(x,7,y,364);
}
