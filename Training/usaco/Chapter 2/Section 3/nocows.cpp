/*
 ID: lakshit4
 LANG: C++
 TASK: nocows
*/

#include <bits/stdc++.h>

using namespace std;

int t[150][250];
int st[150][250];

int main(){
	int N,K;
	ifstream in("nocows.in");
	ofstream out("nocows.out");
	in >> N >> K;
	// cout << N << K << endl;
	t[1][1] = 1;

	for(int i=2;i<=K;i++){
		for(int j=1;j<=N;j+=2){
			for(int k=1;k<=j-1-k;k+=2){
				int factor = (k != j-1-k) ? 2 : 1;
				t[i][j] += factor *
						(st[i-2][k]*t[i-1][j-1-k]  
                        +t[i-1][k]*st[i-2][j-1-k]  
                        +t[i-1][k]*t[i-1][j-1-k]);
                t[i][j] %= 9901;
                // cout << t[i][j] << endl;
			}
		}
		for(int k = 0;k<=N;k++){
				st[i-1][k] += t[i-1][k] + st[i-2][k];
				st[i-1][k] %= 9901;
			}
	}

	out << t[K][N] << endl;
}