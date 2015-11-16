#include <bits/stdc++.h>
using namespace std;

void compress(vector<int> &v) {
    map<int, int> ase;
    for(int i=0 ; i<v.size() ; i++ ) ase[v[i]];

    int k=1;
    for(map<int,int> :: iterator it = ase.begin() ; it!=ase.end() ; it++)
		 cout<<it->first<<endl,it->second = k++;

    for(int x=0 ; x< v.size() ; x++) 
		x = ase[x],cout<<x<<endl;
}

int seq[ 5050 ][ 5050 ];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[ i ];

   // compress(a);

    for(int i = n-1; i >= 0; i--) {
        for(int j = 1; j <= n; j++) seq[ i ][ j ] = seq[ i+1 ][ j ];
        for(int j = a[i]; j <= n; j++) seq[ i ][ j ]++;
    }

	for(int i=0 ; i<=n+1 ; i++)
	{
		for(int j=0 ; j<=n+1 ; j++)
			cout<<seq[i][j]<<" ";
		cout<<endl;
	}
    long long answer = 0;

    for(int i = 0; i<n; i++) {
        for(int j = i+1; j < n; j++) {
            if( a[i] >= a[j] ) continue;
            answer += seq[ j ][ a[i] - 1 ];
        }
    }

    cout << answer << endl;

    return 0;
}
