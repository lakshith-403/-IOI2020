#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3+1;
int g[MAX][MAX];

int main(){
    int n,m;
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }
}