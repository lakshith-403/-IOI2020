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
    int n,a,b;
    cin >> n >> a >> b;
    for(int i=0;i<n;i++){
      int ic = i%b + 'a';
      char c = (char)ic;
      cout << c;
    }
    cout << "\n";
  }
}
