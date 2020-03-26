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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while(q--){
    int l,r;
    cin >> l >> r;
    int sum = 0;
    sum += (int)((r-l+1)/9) * 45;
    for(int i=0;i<(r-l+1)%9;i++)
      sum += getSum(l+i);
    cout << sum << "\n";
  }
}
