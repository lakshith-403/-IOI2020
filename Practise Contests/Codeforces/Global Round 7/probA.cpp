#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int m = n;
    if(n==1)
    {
      cout << -1 << endl;
      continue;
    }
    if(n>3)
    m = n- n%3;
    m--;
    for(int i=1;i<=m;i++)
      cout << 2;
    for(int i=1;i<=n-m;i++)
      cout << 3;
    cout << endl;
  }
}
