/*
ID: lakshit4
PROG: butter
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

ifstream in("butter.in");
ofstream out("butter.out");

vector<int> cows;
vector<vector<int>> graphV(801 , vector<int>());
int graph[801][801];

int dis[501][801];

int N,P,C;
void dijskra(int num){
  int src = cows.at(num);
  int count = 0;
  bool visited[801];
  for(int i=0;i<P;i++)
    visited[i] = false,dis[num][i] = INT_MAX;
  dis[num][src] = 0;
  priority_queue<pair<int,int>> q;
  q.push({0,src});
  pair<int,int> p;
  while(count < P){
    p = q.top();
    q.pop();
    int u = p.second;
    visited[u] = true;
    for(int i : graphV.at(u))
      if(!visited[i] && dis[num][u]+graph[i][u] < dis[num][i]){
        dis[num][i] = dis[num][u]+graph[i][u];
        q.push({dis[num][i]*-1,i});
      }
    count ++;
  }
}

int main(){
  in >> N >> P >> C;
  int n =N;
  while(n--){
    int t;
    in >> t;
    cows.push_back(t-1);
  }
  int c=C;
  while(c--){
    int p1,p2,w;
    in >> p1 >> p2 >> w;
    graph[p1-1][p2-1] = w;
    graph[p2-1][p1-1] = w;
    graphV.at(p1-1).push_back(p2-1);
    graphV.at(p2-1).push_back(p1-1);
  }
  for(int i=0;i<N;i++)
    dijskra(i);
  int minVal = INT_MAX;
  for(int i=0;i<P;i++){
    int sum = 0;
    bool b = true;
    for(int j=0;j<N;j++){
      if(dis[j][i]==INT_MAX || dis[j][i]==INT_MIN){b=false;break;}
      sum += dis[j][i];
    }
    if(b)
    minVal = min(minVal,sum);
  }
  out << minVal << endl;
}
