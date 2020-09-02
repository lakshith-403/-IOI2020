#include <bits/stdc++.h>
#define INF INT_MAX

using namespace std;

const int MAX = 1e2;

//intiialize non-existing edges as INF
int g[MAX][MAX];

void floyd_warshal(){
    for(int k=0;k<n;k++)
        for(int i = 0; i <n; i ++)
            for(int j = 0;j<n; j ++)
                if(g[i][k]<INF && g[k][j]<INF)
                    g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
}