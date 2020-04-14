#include <bits/stdc++.h>
#define ll long long

using namespace std;
bool K[27];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  for(int i=0;i<k;i++){
    char c;
    cin >> c;
    K[c-'a']=true;
  }
  vector<ll> vec;
  ll Count = 0;
  for(int i=0;i<n;i++){
    if(K[s[i]-'a'])Count++;
    else{
      vec.push_back(Count);
      Count = 0;
    }
  }
  if(Count!=0)vec.push_back(Count);
  ll sum = 0;
  for(ll x:vec){
    sum += (x*(x+1)/2);
  }
  cout << sum << "\n";
}

/*
ATTENTION
*
*/
