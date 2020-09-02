/*
ID: lakshith4 
LANG: C++ 
TASK: shuttle
*/

// #pragma GCC target("avx2")
// #pragma GCC optimization("03")
// #pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>

inline void io_setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(string s){
    int n = s.length();
    int i;
    for(int i=0;i<(n-1)/2;i++)
        if(s[i]!='B')return false;
    i++;
    for(i;i<n;i++)
        if(s[i]!='W')return false;
    return true;
}

int n;
bool b = false;
vector<int> ans;

struct node{
    string s;
    vector<int> path;
};

vector<int> solve(string s){
    queue<node> q;
    q.push({s,new vector<int>()});
    while(!q.empty()){
        node n = q.front();
        q.pop();
        if(check(n.s)){
            return n.path;
        }

    }
}

int main(){
    // freopen("shuttle.in",stdin);
    // freopen("shuttle.out",stdout);
    cin >> n;
    string s;
    cin >> s;
}