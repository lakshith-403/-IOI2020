#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    ll a,b,n,s;
    cin >> a >> b >> n >> s;
    if(n*a + b < s){
      cout << "NO" << "\n";
      continue;
    }
    s = max(s-a*n , s%n);
    if(s<=b)cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}
