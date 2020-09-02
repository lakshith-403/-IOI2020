#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3+1;

int low[MAX],tin[MAX],t=0;
bool vis[MAX];

vector<vector<int>> adjList(MAX,vector<int>());

void dfs(int v,int  p = -1){
    vis[v] = true;
    low[v] = tin[v] = t++;
    int children = 0;
    for(int to : adjList[v]){
        if(to==p)continue;
        if(vis[to])
            low[v] = min(low[v],tin[to]);
        else{
            dfs(to,v);
            low[v] = min(low[v],low[to]);
            if(low[to] >= tin[v] && p!=-1)cout << v << "\n";
            ++children;
        }
    }
    if(p==-1 && children>1)cout << v << "\n";
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        adjList.at(a).push_back(b);
        adjList.at(b).push_back(a);
    }
    for(int i=0;i<n;i++)
        low[i] = tin[i] = -1;
    dfs(0);
}