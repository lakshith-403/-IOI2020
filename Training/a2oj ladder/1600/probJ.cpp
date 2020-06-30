#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
  ll a,b;
  cin >> a >> b;
  if(b>(ll)ceil((long double)a/2.0)){
    b -= (ll)ceil((long double)a/2);
    cout << 2*b << "\n";
  }else
    cout << 2*b-1 << "\n";
}
