#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> starts;
vector<pair<int,int>> Ends;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,k;
  cin >> n >> m >> k;
  int K = k;
  while(K--){
    int x,y;
    cin >> x >> y;
    // starts.psuh_back({x,y});
  }
  K = k;
  while(K--){
    int x,y;
    cin >> x >> y;
    // Ends.push_back({x,y});
  }
  cout << 2 * (n - 1) + (n + 1) * (m - 1)<< "\n";
  for(int i=0;i<n-1;i++)
    cout << "D";
  for(int i=0;i<m-1;i++)
    cout << "L";
  for(int i=0;i<n;i++){
    for(int j=0;j<m-1;j++)
      if(i%2==0)cout << "R";
      else cout << "L";
      if(i!=n-1)cout << "U";
  }
  // if(n%2==0)
  //   for(int i=0;i<m-1;i++)
  //     cout << "L";
  // else
  //   for(int i=0;i<m-1;i++)
  //     cout << "R";
  cout << "\n";
}
