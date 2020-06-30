#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

inline ll Min(ll a,ll b){ return a<b?a:b; }
inline ll Max(ll a,ll b){ return a>b?a:b; }

ll delivery(int n,int k,int L,int positions[]){
  ll ans;
  ll CW[n];
  ll ACW[n];
  for(int i=0;i<n;i++){
    if(i<k)CW[i]=Min(L,2*positions[i]);
    else
      CW[i] = CW[i-k]+Min(L,2*positions[i]);
  }
  for(int i=n-1;i>=0;i--){
    if(i>=n-k)ACW[i] = Min(L,2*(L-positions[i]));
    else ACW[i] = Min(L,2*(L-positions[i])) + ACW[i+k];
  }
  ll MIN = Min(CW[n-1],ACW[0]);
  for(int i=1;i<n-1;i++){
    MIN = Min(CW[i]+ACW[i+1],MIN);
  }
  ans = MIN;
  return ans;
}
