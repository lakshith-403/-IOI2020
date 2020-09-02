#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

vector<vector<int>> adjList(100000,vector<int>());

ll solve(int node,int c,int parent){
    ll r = 0;
    if(adjList.at(node).size()==1)return 1;
    else{
        for(int v:adjList.at(node)){
            if(v==parent)continue;
            if(c==1){
                r += solve(v,c+1,node);
            }else{
                r += solve(v,c+1,node);
                r += solve(v,1,node);
            }
        }
    }
    return r;
}

int kingdomDivision(int n, vector<vector<int>> roads) {
    for(int i=0;i<n-1;i++){
        roads[i][0]--,roads[i][1]--;
        adjList.at(roads[i][0]).push_back(roads[i][1]);
        adjList.at(roads[i][1]).push_back(roads[i][0]);
    }
    int src = 0;
    for(int i=0;i<n;i++)
        if(adjList.at(i).size()==1){src = i;break;}
    ll r = solve(adjList[src][0],1,src)*2;
    return r;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> vec(n-1,vector<int>());
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        vec.at(i).push_back(a);
        vec.at(i).push_back(b);
    }
    cout << kingdomDivision(n,vec) << "\n";
    return 0;
}
