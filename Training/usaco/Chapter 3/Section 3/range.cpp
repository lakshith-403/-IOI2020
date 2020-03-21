#include <bits/stdc++.h>

using namespace std;

ifstream in("range.in");
ofstream out("range.out");

int grid[251][251];
int dis[251][251];
int Count[251];
int N;

void BFS(int i,int j){
  cout << i << "<>" << j << endl;
  queue<pair<int,int>> q;
  q.push({i,j});
  dis[i][j] = 0;
  int prev = 0;
  bool visited[N][N];
  for(int r=0;r<N;r++)
    for(int c=0;c<N;c++)
      visited[r][c] = false;
  visited[i][j] = true;
  while(!q.empty()){
    pair<int,int> p = q.front();
    q.pop();
    if(grid[p.first][p.second]==0)break;

    int x = p.first , y = p.second;

    if(dis[x][y]==prev+1){Count[dis[x][y]]++;cout << "new square: " << dis[x][y] << endl;}
cout << x << y << endl;
    cout << dis[x][y]  << " " << prev << endl;
    prev = dis[x][y];
    // if(x+1<N || y+1<)
    // if(x+1<N && !visited[x+1][y]){
      visited[x+1][y] = true;
      q.push({x+1,y});
      dis[x+1][y] = dis[x][y] + 1;
    // }
    // if(y+1<N && !visited[x][y+1]){
      visited[x][y+1] = true;
      q.push({x,y+1});
      dis[x][y+1] = dis[x][y] + 1;
    // }
    // if(x+1<N && y+1<N && !visited[x+1][y+1]){
      visited[x+1][y+1] = true;
      q.push({x+1,y+1});
      dis[x+1][y+1] = dis[x][y] + 1;
    // }
  }
  cout << "___________________________" << endl;
}

int main(){
  int n;
  in >> n;
  N = n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      char c;
      in >> c;
      grid[i][j] = c-'0';
    }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(grid[i][j]==1)BFS(i,j);

  for(int i=2;i<N;i++)
    if(Count[i]!=0)cout << i << " " << Count[i] << endl;
}
