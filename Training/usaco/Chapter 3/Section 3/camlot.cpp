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
  int e[R+1][C+1];
  int minIndex[R+1][C+1];
  for(int r=1;r<=R;r++)
    for(int c=1;c<=C;c++){
      int localMin = INT_MAX;
      int minI = -1;
      int count = 0;
      for(pair<int,int> p : knights){
        int temp = knightDis[p.first][p.second][r][c] + max(delta(king.first,r),delta(king.second,c));
        if(temp < localMin){
          localMin = temp;
          e[r][c] = temp;
          minI = count;
        }
        count++;
      }
      minIndex[r][c] = minI;
    }
  int k[R+1][C+1];
  for(int r=1;r<=R;r++)
    for(int c=1;c<=C;c++){
      int sum = 0;
      for(pair<int,int> p : knights)
        sum += knightDis[p.first][p.second][r][c];
      k[r][c] = sum;
    }
    int MIN = INT_MAX;
  for(int fr=1;fr<=R;fr++)
    for(int fc=1;fc<=C;fc++)
      for(int pr=1;pr<=R;pr++)
        for(int pc=1;pc<=C;pc++){
          int ans;
          if(knights.size()==0)ans = max(delta(pr,fr),delta(fc,pc));
          else
          ans = k[fr][fc] - knightDis[knights.at(minIndex[pr][pc]).first][knights.at(minIndex[pr][pc]).second][fr][fc] + e[pr][pc] + knightDis[pr][pc][fr][fc];
          // if(ans<MIN)cout << fr << "<>" << fc << " " << pr << "<>" << pc << "->" << minIndex[pr][pc] << endl;
          MIN = min(ans,MIN);
        }
  out << MIN << endl;
}
