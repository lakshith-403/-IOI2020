/*
ID: lakshit4
PROG: range
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

ifstream in("range.in");
ofstream out("range.out");

int grid[251][251];
int dis[251][251];
int Count[251];
int N;

void BFS(int i,int j){
  queue<pair<int,int>> q;
  q.push({i,j});
  dis[i][j] = 0;
  int prev = 0;
  bool visited[N][N];
  for(int r=0;r<N;r++)
    for(int c=0;c<N;c++)
      visited[r][c] = false;
  visited[i][j] = true;
  int n=3;
  int C = 0;
  while(!q.empty()){
    pair<int,int> p = q.front();
    q.pop();
    int x = p.first , y = p.second;
    if(grid[x][y]==0)break;
    C++;
    if(!visited[x+1][y]){
      visited[x+1][y] = true;
      q.push({x+1,y});
      dis[x+1][y] = dis[x][y] + 1;
    }
    if( !visited[x][y+1]){
      visited[x][y+1] = true;
      q.push({x,y+1});
      dis[x][y+1] = dis[x][y] + 1;
    }
    if(!visited[x+1][y+1]){
      visited[x+1][y+1] = true;
      q.push({x+1,y+1});
      dis[x+1][y+1] = dis[x][y] + 1;
    }
  }
  n = 3;
  int s = 2;
  C--;
  for(int i=0;C>=0;i++){
    C -= n + 2*i;
    Count[i+1]++;
  }
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

  for(int i=2;i<=N;i++)
    if(Count[i]!=0)out << i << " " << Count[i] << endl;
}
