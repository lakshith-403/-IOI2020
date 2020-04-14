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
    int n;
    cin >> n;
    vector<int> vec;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    for(int i=(n/2)-1;i>=0;i--){
      cout << vec.at(i) << " " << vec.at(n-i-1) << " ";
    }
    cout << "\n";
  }
}

/*
ATTENTION
*
*/
