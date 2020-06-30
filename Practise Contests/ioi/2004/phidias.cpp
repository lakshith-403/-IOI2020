#include <bits/stdc++.h>
#define pi pair<int,int>
#define x first
#define y second
#define shit cout << "shit i'm here \n";

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int w,h,n;
vector<pi> tiles;
const int N = 600;

bool isEnd(int w,int h){
  bitset<N> w_set;
  bitset<N> h_set;
  for(int i=0;i<n;i++)if(w>=tiles[i].x)w_set[i]=1;
  for(int i=0;i<n;i++)if(h>=tiles[i].y)h_set[i]=1;
  w_set &= h_set;
  if(w_set.any())return false;
  else return true;
}

int dp[601][601];

int solve(int w,int h){
  if(dp[w][h]!=-1)return dp[w][h];
  if(isEnd(w,h)){dp[w][h]=w*h;return dp[w][h];}
  int MIN = INT_MAX;
  for(int  i=0;i<n;i++)
    if(w==tiles[i].x && h==tiles[i].y)MIN = 0;
  for(int i=1;i<w;i++){
    int ans = solve(i,h) + solve(w-i,h);
    MIN = min(MIN,ans);
  }
  for(int i=1;i<h;i++){
    int ans = solve(w,i) + solve(w,h-i);
    MIN = min(MIN,ans);
  }
  dp[w][h] = MIN;
  return MIN;
}

int main(){
  ifstream in("phidias.in");
  ofstream out("phidias.out");
  in >> w >> h >> n;
  for(int i=0;i<n;i++){
    int a,b;
    in >> a >> b;
    tiles.push_back({a,b});
  }
  for(int i=0;i<=600;i++)
    for(int j=0;j<=600;j++)
      dp[i][j] = -1;
  out << solve(w,h) << "\n";
  out.flush();
}
