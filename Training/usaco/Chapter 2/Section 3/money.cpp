/*
 ID: lakshit4
 LANG: C++
 TASK: money
*/

#include <bits/stdc++.h>

using namespace std;

long long dp[20000];

int main(){
	ifstream in("money.in");
	ofstream out("money.out");

	int V,N;
	in >> V >> N;
	int coins[V];
	for(int i=0;i<V;i++)
		in >> coins[i];
	dp[0] = 1;
	for(int x : coins)
		for(int i=x;i<=N;i++)
			dp[i] += dp[i-x];


	out << dp[N] << endl;
}