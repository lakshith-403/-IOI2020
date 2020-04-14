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
    ll n;
    cin >> n;
    if(n%2==1){
      cout << (n-1)/2;
    }else{
      cout << (n/2)-1;
    }
    cout << "\n";
  }
}
