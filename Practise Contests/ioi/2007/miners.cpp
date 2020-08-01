#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string lift(string ss){
    string str = "";
    str += ss.substr(1,2);
    str = str + "_";
    return str;
}

int getCount(string str){
    int Count[3] = {0};
    for(char c:str)
    if(c=='_')continue;
    else
    Count[c-'0'] =1;
    int r =  Count[0] + Count[1] + Count[2];
    return r;
}

string s;
int n;
int MAX = 0;

void solve(int pos,string mine1,string mine2,int sum){
    if(pos==n){
        MAX = max(MAX,sum);
        return;
    }
    string m1,m2;
    m1 = lift(mine1);
    m2 = lift(mine2);
    m2[2] = s[pos];
    m1[2] = s[pos];
    pos++;
    solve(pos,m1,mine2,sum+getCount(m1));
    solve(pos,mine1,m2,sum+getCount(m2));
}

int main(){
    io_setup();
    cin >> n >> s ;
    std::replace(s.begin(),s.end(),'M','0');
    std::replace(s.begin(),s.end(),'F','1');
    std::replace(s.begin(),s.end(),'B','2');
    solve(0,"___","___",0);
    cout << MAX << "\n";
}