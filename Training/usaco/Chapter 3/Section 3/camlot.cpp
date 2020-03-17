//commit change
#include <bits/stdc++.h>

using namespace std;

ifstream in("camlot.in");
ofstream out("camlot.out");

int R,C;

vector<pair<int,int>> knights;
pair<int,int> king;

int knightDis[27*31][31][27];
int kingDis[31][27];

void BFS(int num){
    bool visited[31][27];
    for(int i=0;i<=C;i++)
      for(int j=0;j<=R;j++)
        visited[i][j] = false;
    list<pair<int,int>> q;
    visited[knights.at(num).first][knights.at(num).second] = true;
    q.push_back(knights.at(num));
    int count = 0;
    while(!q.empty()){
       pair<int,int> p = q.front();
       knightDis[num][p.first][p.second] = count;
       count ++;
       q.pop_front();
       pair<int,int> next;
       int x,y;
       int r,c;
       for(x = -2;x<=2;x++)
        for(y = -2;y<=2;y++){
          if(x==0 || y==0)continue;
          if(x==y || x*-1==y)continue;
          r = p.first+x;
          c = p.second+y;
          if(r>=1 && r<=R && c>=1 && c<=C && !visited[r][c]){
            q.push_back({r,c});
            visited[r][c] = true;
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
  for(int i=0;i<knights.size();i++)
    BFS(i);
}
