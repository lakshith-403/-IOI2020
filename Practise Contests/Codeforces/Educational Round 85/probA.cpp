#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    bool flag = true;
    int prevP = 0;
    int prevC = 0;
    for(int i=0;i<n;i++){
      int p,c;
      cin >> p >> c;
      if(p<prevP || c<prevC)flag = false;
      if(p-prevP<c-prevC)flag = false;
      prevP = p;
      prevC = c;
    }
    if(flag)cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}
