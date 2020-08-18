#include "fun.h"
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<vector<int>> adjList(501,vector<int>());
int dis[501][501];
int n;
set<int> v;

int getSource(){
  int maxI = -1,MAX = 0;
  for(int i=1;i<n;i++)
    if(dis[0][i]>MAX)MAX = dis[0][i],maxI = i;
  int pos = maxI;
  MAX = 0;
  for(int i=0;i<n;i++)
    if(pos!=i && dis[pos][i]>MAX)MAX = dis[pos][i],maxI = i;
  return pos;
}

int getMax(int src){
  int maxI = -1,MAX = 0;
  for(int i=0;i<n;i++)
    if(i!=src && dis[src][i]>MAX && v.count(i)==0)MAX = dis[src][i],maxI = i;
  return maxI;
}

std::vector<int> createFunTour(int N, int q) {
  n = N;
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
      int w = hoursRequired(i,j);
      if(w==1){
        adjList.at(i).push_back(j);
        adjList.at(j).push_back(i);
      }
      dis[i][j] = dis[j][i] = w;
    }

  vector<int> ans;
  
  int src = getSource();
  v.insert(src);
  ans.pb(src);
  for(int i=1;i<n;i++){
    int a = getMax(src);
    v.insert(a);
    ans.pb(a);
    src = a;
  }
  return ans;
}
