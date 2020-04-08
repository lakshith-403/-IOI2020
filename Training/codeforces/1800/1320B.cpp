#include <bits/stdc++.h>

using namespace std;
int N,M,K;

vector<vector<int>> adjList(2*(int)pow(10,5)+1,vector<int>());
vector<vector<int>> revList(2*(int)pow(10,5)+1,vector<int>());
int dis[200001];
int p[200001];
bool visited[200001];

void BFS(int src){
  dis[src]=0;
  visited[src] = true;
  list<pair<int,int>> q;
  q.push_back({src,0});
  while(!q.empty()){
    pair<int,int> node = q.front();
    dis[node.first] = node.second;
    q.pop_front();
    for(int x:adjList.at(node.first))
      if(!visited[x]){
        visited[x] = true;
        q.push_back({x,node.second+1});
      }
  }
}
int MIN,MAX;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    adjList.at(b).push_back(a);
    revList.at(a).push_back(b);
  }
  cin >> K;
  for(int i=1;i<=K;i++)
    cin >> p[i];
  BFS(p[K]);
  for(int i=1;i<K;i++){
    int Min = INT_MAX;
    int MinCount = 0;
    for(int x:revList.at(p[i])){
      if(dis[x]<Min){
        Min = dis[x];
        MinCount = 1;
      }else if(dis[x]==Min)MinCount++;
    }
    if(dis[p[i+1]]==Min){
      if(MinCount>1){
        MAX++;
      }
    }else{
      MAX++;
      MIN++;
    }
  }
  cout << MIN << " " << MAX << "\n";
}
