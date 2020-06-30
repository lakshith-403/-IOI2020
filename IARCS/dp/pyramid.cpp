#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

inline void io_setup(){
  ios_base::sync_With_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int n,m,a,b,c,d;
int prefSum[1000][1000];

int getSum(int x, int y, int p, int q){
  return prefSum[x+p][y+q]-(prefSum[x][q]+prefSum)
}

int main(){
  io_setup();
  cin >> n >>m >>a >> b >> c >> d;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin >> grid[i][j];
  //setup prefSum array
  for(int i=1;i<n;i++)
    prefSum[i][0]+=prefSum[i-1][0];
  for(int j=1;j<m;j++)
    prefSum[0][j]+=prefSum[0][j-1];
  for(int i=1;i<n;i++)
    for(int j=1;j<n;j++)
      prefSum[i][j] = prefSum[i][j] + prefSum[i-1][j] + prefSum[i][j-1];
  pair<int,int> maxP = {0,0};
  pair<int,int> maxC = {0,0};
  int MAX =0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      
}
