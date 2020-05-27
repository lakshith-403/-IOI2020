#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
vector<pair<int,int>> sizes;
int n;
int DP[700][700];
int solve(int w,int h){
  if(DP[w][h]!=-1)return DP[w][h];
  int MIN = w*h;
  for(int i=0;i<n;i++)
    if(sizes.at(i).x==w && sizes.at(i).y==h)
      return 0;
  for(int i=1;i<w;i++)
    MIN = min(MIN,solve(i,h)+solve(w-i,h));
  for(int i=1;i<h;i++)
    MIN = min(MIN,solve(w,i)+solve(w,h-i));
  DP[w][h] = MIN;
  return MIN;
}
int main(){
  int w,h;
  cin >> w >> h >> n;
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    sizes.push_back({a,b});
  }
  for(int i=0;i<=w;i++)
    for(int j=0;j<=h;j++)
      DP[i][j] = -1;
  cout << solve(w,h);
}
