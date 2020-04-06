#include <bits/stdc++.h>

using namespace std;
int N,M,Q;
int D[1001];
int DP[1001][1001][2];
int main(){
  // ios_base::sync_With_stdio(false);
  // cin.tie(NULL);
  cin >> N >> M;
  for(int i=1;i<=N;i++)
    cin >> D[i];
  for(int p=2;p<=N;p++){
    for(int k=0;k<=M;k++){
      DP[p][k][0] = max(DP[p-1][k][0],DP[p-1][k][1]);
      int a=DP[p-1][k-D[p]][1]+1,b=DP[p-1][k-D[p]-D[p-1]][0]+2;
      cout << "+" << k-D[p] << " " << k-D[p]-D[p-1] << "\n";
      if(k-D[p]<0)
        a = 0;
      if(k-D[p]-D[p-1]<0)
        b = 0;
      DP[p][k][1] = max(a,b);
    }
  }
  for(int p=1;p<=N;p++){
    for(int k=0;k<=M;k++){
      cout << DP[p][k][0] << " "  << DP[p][k][1] << "\t";
    }
    cout << endl;
  }
}
