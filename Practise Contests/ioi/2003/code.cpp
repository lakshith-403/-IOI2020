#include <bits/stdc++.h>

using namespace std;

inline void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int r,h;
map<string,int> m;

int R[1000][3];
int H[1000][3];

int main(){
    io();
    cin >> r >> h;
    int j = 0;
    for(int i=0;i<r;i++){
        string a;
        cin >> a;
        if(m.count(a)==0)m.insert({a,j++});
        R[i][0] = m.at(a);
        cin >> a;
        cin >> a;
        if(m.count(a)==0)m.insert({a,j++});
        R[i][1] = m.at(a);
        cin >> a;
        cin >> a;
        if(m.count(a)==0)m.insert({a,j++});
        R[i][2] = m.at(a);
    }
    for(int i=0;i<h;i++){
        string a;
        cin >> a;
        if(m.count(a)==0)m.insert({a,j++});
        H[i][0] = m.at(a);
        cin >> a;
        cin >> a;
        if(m.count(a)==0)m.insert({a,j++});
        H[i][1] = m.at(a);
        cin >> a;
        cin >> a;
        if(m.count(a)==0)m.insert({a,j++});
        H[i][2] = m.at(a);
    }

    
}