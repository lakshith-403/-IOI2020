#include <bits/stdc++.h>
#include "traffic.h"
#define pb push_back

using namespace std;

vector<vector<int>> adjList(1000000,vector<int>());
int MIN = INT_MAX;
int MINPOS = 0;
int sz[1000000];

int setup(int n,int s,int*p){
  sz[n] = p[n];
  for(int x:adjList.at(n))
    if(x!=s)
      sz[n]+=setup(x,n,p);
  return sz[n];
}

void DFS(int n,int s,int prev,int* p){
  int MAX = prev;
  for(int x:adjList.at(n))
    if(x!=s){
      DFS(x,n,prev+sz[n]-sz[x],p);
      MAX = max(MAX,sz[x]);
    }
  if(MIN>MAX){
    MIN = MAX;
    MINPOS = n;
  }
}

int LocateCentre(int n,int p[],int s[],int d[]){
  for(int i=0;i<n-1;i++){
    adjList.at(s[i]).pb(d[i]);
    adjList.at(d[i]).pb(s[i]);
  }
  setup(0,0,p);
  DFS(0,0,0,p);
  return MINPOS;
}
