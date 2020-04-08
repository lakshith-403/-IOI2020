#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    char arr[n][m];
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(i==0&&j==m-1)cout << "W";
        else cout << "B";
      }
      cout << "\n";
    }
  }
}
