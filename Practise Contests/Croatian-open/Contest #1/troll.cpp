#include <bits/stdc++.h>

using namespace std;

int getSum(int n){
  string s = to_string(n);
  int sum = 0;
  for(char c:s)
    sum += c-'0';
  if(sum>9)return getSum(sum);
  return sum;
}

int main(){
  int q;
  cin >> q;
  while(q--){
    int l,r;
    cin >> l >> r;
    int sum = 0;
    for(int i=l;i<=r;i++)
      sum += getSum(i);
    cout << sum << "\n";
  }
}
