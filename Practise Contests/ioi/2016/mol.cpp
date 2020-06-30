#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second

using namespace std;


vector <int> find_subset (int l, int u, vector <int> w){
  int n = w.size();
  vector<int> r;
  vector<pair<ll,ll>> vec;
  for(int i=0;i<n;i++)vec.pb({w[i],i});
  sort(vec.begin(),vec.end());
  ll sum = 0;
  for(int i=0,j=0;j<n;j++){
    sum += vec[j].f;
    while(sum>u){
      sum -= vec[i++].f;
    }
    if(sum>l){
      for(int k=i;k<=j;k++){
        r.pb(vec[k].s);
      }
      break;
    }
  }
  return r;
}

int main(){
    vector<int> w = {15,16,17,18};
    int result[4];
    int l,u;
    
    while(true){
      cin >> l >> u;
      vector<int> ans = find_subset(l,u,w);
      for(int x:ans)cout << x << " ";
      cout << "\n";
    }
}
