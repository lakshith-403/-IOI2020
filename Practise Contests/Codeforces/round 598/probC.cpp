#include <bits/stdc++.h>
#define ll long long
using namespace std;

int C[10001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m,d;
  cin >> n >> m >> d;
  int sum = 0;
  for(int i=0;i<m;i++){
    cin >> C[i];
    sum += C[i];
  }
  int delta = sum + (m+1)*(d-1);
  // cout << delta << "\n";
  if(delta<n){
    cout << "NO" << "\n";
    return 0;
  }
  cout << "YES" << "\n";
  int pos = 0;
  vector<int> vec;
  for(int i=0;i<delta-n;i++){
    // for(int j=0;j<d-1;j++)
    //   cout << 0;
    // cout << "INFIRST \n";
    for(int j=0;j<C[i];j++)
      vec.push_back(i+1);
  }
  for(int j=0;j<d-1;j++)
    vec.push_back(0);
  // cout << delta-n << "+\n";
  for(int i=delta-n;i<m;i++){
    for(int j=0;j<C[i];j++)
      vec.push_back(i+1);
    for(int j=0;j<d-1;j++)
      vec.push_back(0);
  }
  for(int i=0;i<vec.size()-1;i++)
    cout << vec.at(i) << " ";
  cout << vec.at(vec.size()-1);
  cout << "\n";
}
