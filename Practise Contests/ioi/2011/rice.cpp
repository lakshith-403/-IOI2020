#include <bits/stdc++.h>
#include "ricehub.h"
#define ll long long
#define pb push_back

using namespace std;

inline ll min(ll a,ll b){
  return a<b?a:b;
}

inline ll max(ll a,ll b){
  return a<b?b:a;
}

inline ll abs(ll a,ll b){
  return max(a,b)-min(a,b);
}

int besthub(int r,int l,int x[],ll b){
  int MAX = 0;
  for(int i=0;i<r;i++){
    vector<ll> vec;
    for(int j=0;j<r;j++){
      vec.pb(abs(x[i],x[j]));
    }
    sort(vec.begin(),vec.end());
    int Count = 0;
    ll cost = b;
    while(true){
      if(vec[Count]<=cost)
        cost -= vec[Count++];
      else 
        break;
      if(vec.size()==Count)break;
    }
    MAX = max(MAX,Count);
  }
  return MAX;
}

int main(){
  int r,l;
  cin >> r >> l;
  int x[r];
  for(int i=0;i<r;i++)cin>>x[i];
  ll b;
  cin >> b;
  cout << besthub(r,l,x,b);
}
