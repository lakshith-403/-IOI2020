/*
 ID: lakshit4
 LANG: C++
 TASK: subset
*/

#include <bits/stdc++.h>

using namespace std;

int N,SUM;

int Count = 0;
int mem[40][391];

int main(){
	ifstream in("subset.in");
	ofstream out("subset.out");
	in >> N;
	SUM = N * (N + 1) / 2;
	mem[1][0] = 1;
	mem[1][1] = 1;
	for(int i=2;i<=N;i++){
		for(int j=0;j<=SUM;j++){
			if(j<i) mem[i][j]++;
			mem[i][j+i] += mem[i-1][j];
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<=SUM;j++){
			cout << mem[i][j] << " ";
		}
		cout << endl;
	}
	cout<<mem[N][SUM];
}