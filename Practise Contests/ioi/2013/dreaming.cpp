#include <bits/stdc++.h>
#define pi pair<int,int>
#define f first
#define s second
#define pb push_back

using namespace std;

int MAX_IN = 1e5;

vector<vector<pair<int,int>>> adjList(100000,vector<pair<int,int>>());
vector<pair<int,int>> centers;
int now = 0;
int dis[100000];
int parent[100000];
int visited[100000];
int dist=0;

void bfs(int node){
    now = node , dist = 0 ;
    queue< pair<int , pair<int , int> > >q ;
    q.push({node , {0 , -2}}) ;
    dis[node] = 0 ;
    parent[node] = node ;
    while(!q.empty())
    {
        pair<int , pair<int , int> >p = q.front() ;
        q.pop() ;
        int cur = p.first , d = p.second.first , par = p.second.second ;
        visited[cur] = 1 ;
        parent[cur] = par ;
        if(d > dist)
            now = cur , dist = d ;
        for(auto &child : adjList[cur])
        {
            if(child.first == par)
                continue;
            dis[child.first] = child.second ;
            q.push({child.first , {d + child.second , cur}}) ;
        }
    }
    return ;
}

int travelTime(int n,int m,int l,int a[],int b[],int t[]){
  memset(parent , -1 , sizeof(parent));
  for(int i=0;i<m;i++){
    adjList.at(a[i]).push_back({b[i],t[i]});
    adjList.at(b[i]).push_back({a[i],t[i]});
  }
  for(int i=0;i<n;i++){
    if(visited[i]==1)continue;
//     cout << i << "\n";
    //find the farthest leaf
    bfs(i);
    bfs(now);
//     cout << dist << "\n";
    //only one node
    if(dist==0){centers.pb({0,i});continue;}
    //find the center of the component
    int sum = 0,cur = now,prv=-1;
    for(int j=0;j<n;j++){
      sum += dis[cur];
      prv = cur;
      cur = parent[cur];
      if(sum*2>=dist)break;
    }
    int a = max(sum,dist-sum);
    sum -= dis[prv] ;
    if(max(sum , dist - sum) < a && prv != -1)
        centers.pb({max(sum , dist - sum) , prv}) ;
    else
        centers.pb({a , cur}) ;
//     cout << a << "\n";
  }
  //connect components to make one tree
  sort(centers.rbegin(),centers.rend());
  int v = centers[0].s;
//   cout << v << "\n";
  for(int i=1;i<centers.size();i++){
//     cout  << centers[i].s << "\n";
    adjList.at(v).pb({centers[i].s,l});
    adjList.at(centers[i].s).pb({v,l});
  }
  bfs(0);
  bfs(now);
//   cout << dist << "\n";
  return dist;
}

// int main(){
//   int n=12,m=8,l=2;
//   int a[] = {0,8,2,5,5,1,1,10};
//   int b[] = {8,2,7,11,1,3,9,6};
//   int t[] = {4,2,4,3,7,1,5,3};
//   travelTime(n,m,l,a,b,t);
// }
