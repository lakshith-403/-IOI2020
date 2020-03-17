#include<bits/stdc++.h>

using namespace std;

int counts[7];

int makeRoman(int n){
	while(n>0){
		
	}
}

int  main(){
	ifstream in("preface.in");
	ofstream out("preface.out");

	int n;
	in >> n;

	for(int i=0;i<7;i++)
		counts[i]=0;
	for(int i=1;i<=n;i++)
		makeRoman(i); 
}

