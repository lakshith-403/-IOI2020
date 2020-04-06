#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n,m;
  cin >> n >> m;
  vector<long long> vec;
  vector<long long> l;
  long long sum = 0;
  l.push_back(-1);
  long long MIN = INT_MAX;
  for(long long i=0;i<m;i++){
    long long L;
    cin >> L;
    l.push_back(L);
    sum += L;
  }
  if(sum<n){cout << "-1" << "\n";return 0;}
  long long N = n;
  sum++;
  for(long long i=1;i<=m;i++){
    sum -= l.at(i);
    long long j;
    for(j=N-l.at(i)+1;j>0;j--)
      if(j<=sum)break;
    vec.push_back(j);
    MIN = min(MIN,j);
    if(j<1){cout << "-1" << "\n";return 0;}
    N = j + l.at(i) - 2;
  }
    if(MIN!=1){cout << "-1" << "\n";return 0;}
  for(long long i=0;i<vec.size()-1;i++)
    cout << vec.at(i) << " ";
  cout << vec.at(vec.size()-1) << "\n";
}
