#include <bits/stdc++.h>

using namespace std;
int n,k;
int main(){
  int t;
  cin >> t;
  for(int j=0;j<t;j++){
    cin >> n >> k;
    int single;
    single = k/n;
    if(k - (single*n) != 0)
      cout << k - n + (k/2) << endl;
    else
      cout << n << endl;
  }
}
