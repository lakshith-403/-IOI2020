/*
ID: lakshit4
PROG: camelot
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

ifstream in("camelot.in");
ofstream out("camelot.out");

int R,C;

vector<pair<int,int>> knights;
pair<int,int> king;

int knightDis[27][31][31][27];
int kingDis[31][27];

int delta(int a,int b){
  if(a==b)return 0;
  return max(a,b) - min(a,b);
}

void BFS(int a,int b){
    bool visited[31][27];
    for(int i=0;i<=C;i++)
      for(int j=0;j<=R;j++){
        knightDis[a][b][i][j] = INT_MAX;
        visited[i][j] = false;
      }
    list<pair<int,int>> q;
    visited[a][b] = true;
    q.push_back({a,b});
    knightDis[a][b][a][b] = true;
    knightDis[a][b][a][b] = 0;
    while(!q.empty()){
       pair<int,int> p = q.front();
       q.pop_front();
       int x,y;
       int r,c;
       for(x = -2;x<=2;x++)
        for(y = -2;y<=2;y++){
          if(x==0 || y==0)continue;
          if(x==y || x*-1==y)continue;
          int r = p.first +x;
          int c = p.second +y;
          if(r<=R && c<=C && r>=1 && c>=1 && !visited[r][c]){
            q.push_back({r,c});
            visited[r][c] = true;
            knightDis[a][b][r][c] = knightDis[a][b][p.first][p.second] + 1;
          }
        }
    }
}

int main(){
  in >> R >> C;
  char c;
  int r;
  in >>c;
  in >>r;
  king = {r,c-'A'+1};
  while(in >> c){
    in >> r;
    knights.push_back({r,c-'A'+1});
  }
  for(int i=1;i<=R;i++)
    for(int j=1;j<=C;j++)
      BFS(i,j);

  int MIN = INT_MAX;
  for(int fr=1;fr<=R;fr++)
    for(int fc=1;fc<=C;fc++)
      for(int pr=1;pr<=R;pr++)
        for(int pc=1;pc<=C;pc++){
          int D = 0;
          for(pair<int,int> knight : knights){
            D += knightDis[knight.first][knight.second][fr][fc];
          }
          int d;
          int e;
          int localMin = INT_MAX;
          for(int i=0;i<knights.size();i++){
            d = D - knightDis[knights.at(i).first][knights.at(i).second][fr][fc];
            e = knightDis[knights.at(i).first][knights.at(i).second][pr][pc] + knightDis[pr][pc][fr][fc] + max(delta(pr,fr),delta(fc,pc));
            localMin = min(localMin,d+e);
          }
          if(knights.size()==0)localMin = max(delta(pr,fr),delta(fc,pc));
          MIN = min(MIN,localMin);
        }
  out << MIN << endl;
}
