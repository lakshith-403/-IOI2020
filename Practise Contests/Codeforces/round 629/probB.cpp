#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >>k;
    int i = 1;
    int total = 0;
    while(total < k){
      total += i;
      i++;
    }
    // cout << i << endl;
    total -= i;
    k-=total;
    // cout << k << endl;
    k--;
    int b1,b2;
    b1 = n-i;
    b2 = n-k;
    for(int j=0;j<n;j++){
      if(j==b1 || j==b2)cout << "b";
      else cout << "a";
    }
    cout << endl;
  }

}
