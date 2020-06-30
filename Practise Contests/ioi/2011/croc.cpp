/*
 * IOI 2011 - Crocodile
 * Tags: Graph, Shortest Path
 * Do reverse dijsktra from multiple exits maintaing the second shortest path length
 * second shortest path length of the start node is the answer
 *  ~ Lakshith Nishshanke
 */


#include <bits/stdc++.h>
#include "crocodile.h"
#define pb push_back

using namespace std;

vector<vector<pair<int,int>>> adjList(1001,vector<pair<int,int>>());

int travel_plan(int n,int m,int r[][2],int l[],int k,int p[]){
  for(int i=0;i<m;i++){
    adjList.at(r[i][0]).pb({r[i][1],l[i]});
    adjList.at(r[i][1]).pb({r[i][0],l[i]});
  }
  //dijsktra
  priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
  vector<pair<int,int>> dist(n);
  for(int i=0;i<n;i++)
    dist.at(i) = {INT_MAX,INT_MAX};
  for(int i=0;i<k;i++){
    pq.push({0,p[i]});
    dist.at(p[i]) = {0,0};
  }
  while(!pq.empty()){
    int cost = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if(cost > dist[node].second)continue;
    for(pair<int,int> v : adjList.at(node)){
      int to = v.first;
      int nCost = cost + v.second;
      int prv = dist[to].second;
      if(nCost<dist[to].first)
        dist[to].second = dist[to].first,dist[to].first=nCost;
      else if(nCost<dist[to].second)
        dist[to].second = nCost;
      if(dist[to].second<prv)
        pq.push({dist[to].second,to});
    }
  }
  return dist[0].second;
}
