#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;

vector<vector<int,int>> adjList(MAX,vector<int>());
vector<int> path;

inline int searchVec(int v,int p){
    for(int i=0;i<adjList.at(p).size();i++)
        if(adjList[p][i]==v)return i;
    return -1;
}

void findPath(int v){
    for(int x:adjList[v]){
        adjList[x].erase(adjList[x].begin()+searchVec(v,x));
        adjList[v].erase(adjList[v].begin()+searchVec(x,v));
        findPath(v);
    }
    path.push_back(v);
}

int main(){
    int n,m;
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        adjLst.at(a).push_back(b);
        adjList.at(b).push_back(a);
    }
    findPath(0);
    for(int v:path)cout << v << "\t";
}