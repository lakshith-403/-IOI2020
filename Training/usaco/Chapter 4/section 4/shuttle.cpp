/*
ID: lakshith4 
LANG: C++ 
TASK: shuttle
*/

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

void solve(string s){
    int i;
    for(i=0;i<n;i++){
        if(s[i]==' ')break;
    }
    
}

int main(){
    freopen("shuttle.in",stdin);
    freopen("shuttle.out",stdout);
    cin >> n;
    string s;
    cin >> s;
}