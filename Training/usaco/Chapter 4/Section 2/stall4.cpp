/*
ID: lakshit4
PROG: stall4
LANG: C++
*/

#include <bits/stdc++.h>
#define in cin
#define out cout

using namespace std;

inline void setup_io(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

vector<vector<int>> pref(201,vector<int>());

const int MAX = 402;

int grid[MAX][MAX];
const int src = 400;
const int sink = 401;


int prevNode[MAX];
int visited[MAX];
int flow[MAX];


int getMaxflow(){
  int n = MAX;
  int totalFlow = 0;
  while(true){
    for(int i=0;i<n;i++){
      prevNode[i]=-1;
      visited[i]=false;
      flow[i]=0;
    }
    flow[src] = INT_MAX;
    int maxFlow = 0;
    int maxLoc = -1;
    while(true){
      maxFlow = 0;
      maxLoc = -1;
      for(int i=0;i<n;i++){
        if(flow[i]>maxFlow && !visited[i]){
          maxFlow = flow[i];
          maxLoc = i;
        }
      }
      if(maxLoc==-1 || maxLoc==sink)break;
      visited[maxLoc] = true;
      for(int i=0;i<n;i++){
        if(grid[maxLoc][i]!=0 && maxLoc!=i){
          if(flow[i]<min(maxFlow,grid[maxLoc][i])){
            prevNode[i] = maxLoc;
            flow[i] = min(maxFlow,grid[maxLoc][i]);
          }
        }
      }
    }
    if(maxLoc==-1)break;
    int pathCap = flow[sink];
    totalFlow += pathCap;
    int curNode= sink;
    while(curNode!=src){
      int nextNode = prevNode[curNode];
      grid[nextNode][curNode]-=pathCap;
      grid[curNode][nextNode]+=pathCap;
      curNode = nextNode;
    }
  }
  return totalFlow;
}

int main(){
  ifstream in("stall4.in");
  ofstream out("stall4.out");
  int n,m;
  in >> n >> m;
  for(int i=0;i<n;i++){
    grid[src][i] = INT_MAX;
    int a;
    in >> a;
    while(a--){
      int b;
      in >> b;
      grid[i][200+b-1]=1;
    }
  }
  for(int i=0;i<m;i++){
    grid[200+i][sink]=1;
  }
  out << getMaxflow() << "\n";
}
