/*
 ID: lakshit4
 LANG: C++
 TASK: concom
*/

#include <bits/stdc++.h>

using namespace std;

int dp[101][101];

/*int dfs(int i, int j){
	int ans = 0;
	if(dp[i][j]>50)
		for(int k=1;k<101;k++)
				ans += dp[j][k] + dfs(j,k);
	return ans;
}*/

int main(){
	ifstream in("concom.in");
	ofstream out("concom.out");

	int n;
	in >> n;


	for(int i=0;i<n;i++){
		int c1,c2,p;
		in >> c1 >> c2 >> p;
		dp[c1][c2] += p;
	}

	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			if(dp[i][j]>50)
				for(int k=1;k<101;k++)
					dp[i][k] += dp[j][k];// + dfs(j,k);			
		}
	}

	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			if(dp[i][j]>50)
				out << i << " " << j << endl;
}