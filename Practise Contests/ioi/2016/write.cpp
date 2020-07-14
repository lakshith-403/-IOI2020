#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int def[60];
int cur[60];

bool match(){
    for(int i=0;i<60;i++)
        if(def[i]!=cur[i])return false;
    return true;
}

int num(char c){
    if(c<='Z'&&c>='A')
        return (c-'A'+26);
    return (c-'a');
}

int main(){
    io_setup();
    ifstream in("writing.in");
    ofstream out("writing.out");
    int g,n;
    in >> g >> n;
    string w,s;
    in >> w >> s;
    for(char c:w)def[num(c)]++;
    for(int i=0;i<w.length();i++){
        char c = s[i];
        cur[num(c)]++;
    }
    int Count = 0;
    if(match())Count++;
    for(int i=w.length();i<s.length();i++){
        char c = s[i];
        cur[num(c)]++;
        cur[num(s[i-g])]--;
        if(match())Count++;
    }
    out << Count << "\n";
}