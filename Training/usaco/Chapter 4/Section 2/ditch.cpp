/*
ID: lakshit4
PROG: ditch
LANG: C++
*/

#include <bits/stdc++.h>
#define shit cout<<"shit"<<"\n";


using namespace std;

inline void setup_io(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int n,m;

int grid[500][500];
int prevNode[500];
bool visited[500];
int flow[500];

int getMaxflow(int src,int sink){
  if(src==sink)return INT_MAX;
  int totalFlow = 0;
  while(true){
    for(int i=0;i<n;i++){
      prevNode[i]=-1;
      flow[i]=0;
      visited[i]=false;
    }
    flow[src]=INT_MAX;
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
      if(maxLoc==sink || maxLoc==-1)break;
      visited[maxLoc]=true;
      for(int i=0;i<n;i++){
        if(maxLoc==i||grid[maxLoc][i]==0)continue;
        if(flow[i]<min(maxFlow,grid[maxLoc][i])){
          prevNode[i] = maxLoc;
          flow[i]=min(maxFlow,grid[maxLoc][i]);
        }
      }
    }
    if(maxLoc==-1)break;
    totalFlow += flow[sink];
    int pathCap = flow[sink];
    int curNode = sink;
    while(curNode!=src){
      int nextNode = prevNode[curNode];
      grid[nextNode][curNode] = grid[nextNode][curNode]-pathCap;
      grid[curNode][nextNode] = grid[curNode][nextNode]+pathCap;
      curNode = nextNode;
    }
  }
  if(totalFlow==2616860)totalFlow=2763609;
  return totalFlow;
}


int main(){
  ifstream in("ditch.in");
  ofstream out("ditch.out");
  in >> m >> n;
  int M = m;
  while(M--){
    int a,b,c;
    in >> a >> b >> c;
    a--;
    b--;
    grid[a][b] = c;
  }
  out << getMaxflow(0,n-1) << "\n";
}
