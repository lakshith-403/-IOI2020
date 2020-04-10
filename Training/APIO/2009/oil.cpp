#include <bits/stdc++.h>

using namespace std;

int arr[1501][1501];
int TL[1501][1501],TR[1501][1501],BL[1501][1501],BR[1501][1501],sum[1501][1501];
int N,M,K;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M >> K;
  for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)
      cin >> arr[i][j];
  //calculate sum
  for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++){
      int cur = 0;
      cur+=arr[i][j];
      cur-=sum[i-1][j-1];
      sum[i][j] = cur;
    }
  //calculate TL
  for(int i=K;i<=M;i++)
    for(int j=K;j<=N;j++){
      int cur = sum[i][j] - sum[i][j-K] - sum[i-K][j] + sum[i-K][j-K];
      TL[i][j] = max(cur,max(TL[i-1][j],TL[i][j-1]));
    }
  //calculate TR
  for(int i=K;i<=M;i++)
    for(int j=N-K;j>=1;j--){
      int cur = (sum[i][N]-sum[i][j]) - (sum[i-K][N]-sum[i-K][j]) - (sum[i][N]-sum[i][j+K]) + (sum[i-K][N]-sum[i-K][j+K]);
      TR[i][j] = max(cur,max(TR[i-1][j],[i][j+1]));
    }
  //calculate BL
  for(int i=M-K;i>=1;i--)
    for(int j=K;j<=N;j++){
      int cur = (sum[M][j]-sum[i][j]) - (sum[M][j]-sum[i+K][j]) - (sum[M][j-K]-sum[i][j-K]) + (sum[M][j-K]-sum[i+K][j-K]);
      BL[i][j] = max(cur,max(BL[i+1][j],BL[i][j-1]));
    }
  //calculate BR
  for(int i=M-K;i>=1;i--)
    for(int j=N-K;j>=1;j--){
      int cur = (sum[M][N]-)
    }
}
