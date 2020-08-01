#include <bits/stdc++.h>
#define pi pair<int,int>
#define f first
#define s second
#define pb push_back

using namespace std;

inline void io_setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n,c;
const int MAX_IN = 1e3;
vector<vector<int>> adjList(MAX_IN,vector<int>());

string solve(int l,int r){
    if(max(l,r)-min(l,r)<=1)return "";
    for(int x:adjList.at(l+1)){
        
    }
}

int main(){
    io_setup();
    cin >> c >> n;
    for(int i=0;<n;i++){
        int a,b;
        cin >> a >> b;
        adjList.at(a).pb(b);
        adjList.at(b).pb(a);
    }
}