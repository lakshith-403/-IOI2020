/*
ID: lakshit4
PROG: rockers
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream in("rockers.in");
ofstream out("rockers.out");

int N,T,M;
int lengths[25];
int dp[25][25][25];

int main(){
  in >> N >> T >> M;
  for(int i=1;i<=N;i++)
    in >> lengths[i];
  int MAX = INT_MIN;
  for(int i=0;i<M;i++){
    for(int j=0;j<=T;j++){
      for(int k=0;k<=N;k++){
        for(int l=k+1;l<=N;l++){
            if(j+lengths[l]<=T){
              if(dp[i][j][k]+1>dp[i][j+lengths[l]][l])
                dp[i][j+lengths[l]][l]=dp[i][j][k]+1;
            }else{
              if(dp[i][j][k]+1>dp[i+1][lengths[l]][l])
                dp[i+1][lengths[l]][l]=dp[i][j][k]+1;
              }
        }
        MAX = max(MAX,dp[i][j][k]);
      }
    }
  }
  out << MAX << endl;
}
