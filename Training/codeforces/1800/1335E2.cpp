#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vout.tie(NULL);
}

void solve(int t){
  int n;
  cin >> n;
  string s,t;
  cin >>s >> t;
  int a,b;
  for(int i=0;i<n;i++){
    if(s[i]=='1')a++;
    else b++;
    if(t[i]=='1')a--;
    else b--;
  }
  if(a!=0 || b!=0){cout << -1 << "\n";return;}
  
}

int main(){
  int t;
  cin >> t;
  while(t--)solve(t+1);
}
