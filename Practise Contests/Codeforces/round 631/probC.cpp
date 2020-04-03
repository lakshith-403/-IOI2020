#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin >> n >> m;
  vector<int> vec;
  vector<int> l;
  int sum = 0;
  l.push_back(-1);
  int MIN = INT_MAX;
  for(int i=0;i<m;i++){
    int L;
    cin >> L;
    l.push_back(L);
    sum += L;
  }
  // sort(l.begin(),l.end());
  if(sum<n){cout << "-1" << "\n";return 0;}
  int N = n;
  sum++;
  for(int i=1;i<=m;i++){
    // cout << "+" << N << "\n";
    sum -= l.at(i);
    int j;
    for(j=N-l.at(i)+1;j>0;j--){
      // cout << ">" << j << "\n";
      if(j<=sum)break;
    }
    // cout << "<" << j << "\n";
    vec.push_back(j);
    MIN = min(MIN,j);
    if(j<1){cout << "-1" << "\n";return 0;}
    N = j + l.at(i) - 2;
  }
    if(MIN!=1){cout << "-1" << "\n";return 0;}
  for(int i=0;i<vec.size()-1;i++)
    cout << vec.at(i) << " ";
  cout << vec.at(vec.size()-1) << "\n";
}
