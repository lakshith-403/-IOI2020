#include <bits/stdc++.h>

using namespace std;


const int MAX = 1e3+1;

bool vis[MAX];
int low[MAX],tin[MAX];
int t = 0;

vector<vector<int>> adjList(MAX,vector<int>());

void dfs(int v,int p = -1){
    vis[v] = true;
    low[v] = tin[v] = t++;
    for(int to : adjList.at(v)){
        if(to==p)continue;
        if(vis[to])
            low[v] = min(low[v],tin[to]);
        else{
            dfs(to,v);
            low[v] = min(low[v],low[to]);
            if(low[to]>tin[v]){
                cout << v << " " << to << "\n";
            }
        }
    }
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