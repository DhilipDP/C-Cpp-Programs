#include<iostream>
#include<stdio.h>
using namespace std;

char v[]={'1','a','e','i','o','u'};
char c[]={'1','b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
int vowels[256];
int consonants[256];//=


int main(){
	int i;
	vowels['a']=1;
	vowels['e']=2;
	vowels['i']=3;
	vowels['o']=4;
	vowels['u']=5;
	consonants['b']=1;consonants['c']=2;consonants['d']=3 ; consonants['f']=4;
	consonants['g']=5; consonants['h']=6;consonants['j']=7;consonants['k']=8;
	consonants['l']=9;consonants['m']=10;consonants['n']=11;consonants['p']=12;
	consonants['q']=13;consonants['r']=14;consonants['s']=15;consonants['t']=16;
	consonants['v']=17;consonants['w']=18;consonants['x']=19;consonants['y']=20;consonants['z']=21;
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int charac[256]={0};
		string number;
		cin>>number;
		string ans="";
		for(long int i=0 ; number[i] ; i++){
			charac[number[i]]++;
			int st;
			int count = charac[number[i]];
			if(number[i]=='a' || number[i]=='e' || number[i]=='i' || number[i]=='o' || number[i]=='u')
				st=1;
			else
				st=2;
			if(st==1){
				int occ = (count-1)*5 + vowels[number[i]];
				ans += c[occ%21];
			}
			else{
				int occ = (count-1)*21 + consonants[number[i]];
				ans += v[occ%5];
			}
				
		}
		cout<<ans<<endl;
	}
}
