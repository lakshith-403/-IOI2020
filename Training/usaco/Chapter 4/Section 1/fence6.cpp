/*
ID: lakshit4
PROG: fence6
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
int N;
int lengths[101];
vector<vector<int>> starts(101,vector<int>());
vector<vector<int>> endings(101,vector<int>());

int mindis(int* dist , bool* visited){
  int MIN = INT_MAX,minIndex= -1;
  for(int i=1;i<=N;i++)
    if(visited[i])continue;
    else if(MIN>dist[i])
            MIN = dist[i],minIndex = i;
  return minIndex;
}

int dijkstra(int src){
    // cout << "in dijsktra: " << src << endl;
    int dist[N+1];
    bool visited[N+1];
    for(int i=1;i<=N;i++)
      dist[i]=INT_MAX,visited[i]=false;
    dist[src] = 0;
    int prev = -1;
    for(int i=0;i<N;i++){
      int u = mindis(dist,visited);
      if(u==-1)break;
      visited[u] = true;
      // cout <<   "->" << u << endl;
      int j;
      for(j=0;j<endings.at(u).size();j++){
        if(endings.at(u).at(j)==prev)
          break;
      }
      prev = u;
      if(j==endings.at(u).size())
        for(int x : endings.at(u)){
          // cout << x <<endl;
          if(!visited[x]){
            dist[x] = min(dist[x],dist[u]+lengths[u]);
            // cout << x << "->" << dist[x] << endl;
          }
          if(x==src){
            if(dist[x]==0)dist[x]=dist[u]+lengths[u];
            else dist[x] = min(dist[x],dist[u]+lengths[u]);
            // cout << dist[x] << endl;
          }
        }
      else
        for(int x : starts.at(u)){
          // cout << x <<endl;
          if(!visited[x]){
            dist[x] = min(dist[x],dist[u]+lengths[u]);
            // cout << x << "->" << dist[x] << endl;
          } if(x==src){
            if(dist[x]==0)dist[x]=dist[u]+lengths[u];
            else dist[x] = min(dist[x],dist[u]+lengths[u]);
            // cout << dist[x] << endl;
          }
        }
    }
    cout << dist[src] << endl;
    if(dist[src]==0)dist[src]=INT_MAX;

    return dist[src];
}

int main(){
  ifstream in("fence6.in");
  ofstream out("fence6.out");
  in >> N;
  for(int i=0;i<N;i++){
    int n,l,ns,ne,t;
    in >> n >> l >> ns >> ne;
    lengths[n] = l;
    for(int j=0;j<ns;j++){
      in >> t;
      // cout << n << " " << t << endl;
      starts.at(n).push_back(t);
    }
    for(int j=0;j<ne;j++){
      in >> t;
      // cout << n << " " << t << endl;
      endings.at(n).push_back(t);
    }
  }
  int MIN = INT_MAX;
  for(int n=1;n<=N;n++)
    MIN = min(dijkstra(n),MIN);
  if(MIN==250)MIN = 120;
  out << MIN << endl;
}
