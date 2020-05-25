/*
 * Lakshith Nishshanke
 * 2020/05/20 2.55 AM 
*/

#include <bits/stdc++.h>
#define rad 100
#define x first
#define y second
#define MAX_SIZE 522
using namespace std;

int l,w,n;
int START = 520,END=521;;

vector<pair<int,int>> solds;

int grid[MAX_SIZE][MAX_SIZE];

int getMaxFlow(int src,int sink){
    int flow[MAX_SIZE];
    int prev[MAX_SIZE];
    bool visited[MAX_SIZE];
    int totalFlow = 0;
    n = MAX_SIZE;
    while(true){
      for(int i=0;i<n;i++){
       flow[i]=0;
       prev[i]=-1;
       visited[i]=false;
      }
      flow[src] = INT_MAX;
      int maxFlow = 0;
      int maxLoc = -1;
      while(true){
        maxFlow = 0;
        maxLoc = -1;
        for(int i=0;i<n;i++)
          if(!visited[i]&&flow[i]>maxFlow){
           maxFlow = flow[i];
           maxLoc = i;
          }
        if(maxLoc==-1 || maxLoc==sink)break;
        visited[maxLoc] = true;
        for(int i=0;i<n;i++){
          if(i==maxLoc || grid[maxLoc][i]==0)continue;
          if(flow[i]<min(maxFlow,grid[maxLoc][i])){
            flow[i] = min(maxFlow,grid[maxLoc][i]);
            prev[i] = maxLoc;
          }
        }
      }
      if(maxLoc==-1)break;
      int pathCap = flow[sink];
      totalFlow += pathCap;
      int curNode = sink;
      int index = 0;
      while(curNode!=src){
        int nextNode = prev[curNode];
        grid[nextNode][curNode]-=pathCap;
        grid[curNode][nextNode]+=pathCap;
        curNode = nextNode;
      }
    }
    return totalFlow;
}

bool checkMerge(pair<int,int> c1 , pair<int,int> c2){
  int minDis = (int)sqrt((int)pow(c1.x-c2.x,2)+(int)pow(c1.y-c2.y,2));
  if(rad*2 >= minDis)return true;
  return false;
}

int main(){
  ifstream in("testdata-escape\\escape\\escape.i10-5");
  in >> l >> w >> n;
  for(int i=0;i<n;i++){
    int x,y;
    in >> x >> y;
    solds.push_back({x,y});
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j)continue;
      if(checkMerge(solds.at(i),solds.at(j))){
        grid[(i*2)+1][j*2] = INT_MAX-10000;
        grid[(j*2)+1][i*2] = INT_MAX-10000;
      }
    }
  }
  for(int i=0;i<n;i++){
    grid[2*i][(2*i)+1] = 1;
    if(checkMerge(solds.at(i),{solds.at(i).x,0-rad}))grid[START][i*2]=INT_MAX-10000;
    if(checkMerge(solds.at(i),{solds.at(i).x,l+rad}))grid[(i*2)+1][END] = INT_MAX-10000;
  }
  cout << getMaxFlow(START,END);
}
