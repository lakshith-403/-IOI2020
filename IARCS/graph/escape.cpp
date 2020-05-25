#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

vector<pair<int,int>> solds;

vector<vector<int>> adjList(250,vector<int>());

vector<int> starts;
bool endings[250];

bool checkMerge(pair<int,int> c1 , pair<int,int> c2){
  float euDis = sqrt((c1.x-c2.x)*(c1.x-c2.x) + (c1.y-c2.y)*(c1.y-c2.y));
  if((int)euDis <= 200)return true;
  else return false;
}
bool visited[250];
bool DFS(int src){
  if(endings[src])return true;
  bool r = false;
  for(int i:adjList.at(src))
    if(!visited[i]){
      visited[i]=true;
      if(!r)r = DFS(i);
    }
  return r;
}

int main(){
  int l,w,n;
  cin >> l >> w >> n;
  int N = n;
  int index = 0;
  while(N--){
    int x,y;
    cin >> x >> y;
    solds.push_back({x,y});
    if(checkMerge(solds[index],{solds.at(index).first,0}))starts.push_back(index);
    if(checkMerge(solds[index],{solds.at(index).first,w}))endings[index]=true;
    index++;
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(i==j)continue;
      if(checkMerge(solds[i],solds[j])){
        adjList.at(i).push_back(j);
        adjList.at(j).push_back(i);
      }
    }
  bool r = false;
  for(int src : starts)
    if(!r)r = DFS(src);
  if(!r)cout << 0 << "\n";
  else cout << 1 << "\n";
  return 0;
}
